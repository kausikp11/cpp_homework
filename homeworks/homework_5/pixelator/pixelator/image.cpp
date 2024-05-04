#include <pixelator/image.hpp>

pixelator::Image::Image(const int row, const int col)
    : cols_{col}, rows_{row}, pixels_(row * col) {
  size_.cols = col, size_.rows = row;
}

pixelator::Image::Image(const Image& ref_obj) {
  this->cols_ = ref_obj.cols_;
  this->rows_ = ref_obj.rows_;
  this->pixels_ = ref_obj.pixels_;
}

pixelator::Image::Image(pixelator::Size size)
    : cols_{size.cols}, rows_{size.rows}, pixels_(size.rows * size.cols) {}

pixelator::Image::Image(Image&& other_image) {
  this->cols_ = other_image.cols_;
  this->rows_ = other_image.rows_;
  this->pixels_ = other_image.pixels_;
  other_image.cols_ = 0;
  other_image.rows_ = 0;
  other_image.pixels_.clear();
}

bool pixelator::Image::empty() const { return this->pixels_.empty(); }

int pixelator::Image::rows() const { return this->rows_; }
int pixelator::Image::cols() const { return this->cols_; }
pixelator::Size pixelator::Image::size() const { return this->size_; }
ftxui::Color& pixelator::Image::at(int row, int col) {
  return this->pixels_[cols_ * row + col];
}
const ftxui::Color& pixelator::Image::at(int row, int col) const {
  return this->pixels_[cols_ * row + col];
}
pixelator::Image::~Image() {}