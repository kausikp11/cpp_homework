#include <pixelator/stb_image_data_view.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

pixelator::StbImageDataView::StbImageDataView()
    : cols_{0}, rows_{0}, channels_{0}, image_{nullptr} {}

pixelator::StbImageDataView::StbImageDataView(
    std::filesystem::path image_path) {
  if (!std::filesystem::exists(image_path)) {
    std::cerr << "Failed to open the image: " << image_path << std::endl;
    this->cols_ = 0;
    this->rows_ = 0;
    this->channels_ = 0;
  } else {
    this->image_ = stbi_load(
        image_path.c_str(), &this->cols_, &this->rows_, &this->channels_, 0);
  }
  this->size_of_image_.cols = this->cols_;
  this->size_of_image_.rows = this->rows_;
}

pixelator::StbImageDataView::StbImageDataView(StbImageDataView&& other_image)
    : rows_{other_image.rows_},
      cols_{other_image.cols_},
      channels_{other_image.channels_},
      image_{other_image.image_} {
  other_image.image_ = nullptr;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;
}

pixelator::StbImageDataView& pixelator::StbImageDataView::operator=(
    pixelator::StbImageDataView&& other_image) {
  if (this == &other_image) { return *this; }  // Do not self-assign.
  if (image_) stbi_image_free(image_);

  image_ = other_image.image_;

  rows_ = other_image.rows_;
  cols_ = other_image.cols_;
  channels_ = other_image.channels_;

  other_image.image_ = nullptr;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;

  return *this;
}

bool pixelator::StbImageDataView::empty() const {
  if (this->size_of_image_.rows == 0 && this->size_of_image_.cols == 0) {
    return true;
  }
  return false;
}

pixelator::Size pixelator::StbImageDataView::size() const {
  return this->size_of_image_;
}

int pixelator::StbImageDataView::rows() const {
  return this->size_of_image_.rows;
}
int pixelator::StbImageDataView::cols() const {
  return this->size_of_image_.cols;
}

const ftxui::Color pixelator::StbImageDataView::at(int row, int col) const {
  const auto index{channels_ * (row * cols_ + col)};
  const ftxui::Color color{
      this->image_[index], this->image_[index + 1], this->image_[index + 2]};
  return color;
}

pixelator::StbImageDataView::~StbImageDataView() {
  stbi_image_free(this->image_);
}
