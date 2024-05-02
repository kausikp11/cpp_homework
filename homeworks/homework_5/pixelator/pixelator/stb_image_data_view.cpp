#include <pixelator/stb_image_data_view.hpp>

pixelator::StbImageDataView::StbImageDataView(
    std::filesystem::path image_path) {
  if (!std::filesystem::exists(image_path)) {
    std::cerr << "Failed to open the image: " << image_path << std::endl;
    this->size_of_image_.col = 0;
    this->size_of_image_.row = 0;
    this->channels_ = 0;
  } else {
    this->image_ = stbi_load(image_path.c_str(),
                             this->size_of_image_.col,
                             this->size_of_image_.row,
                             this->channels_,
                             0);
  }
}

/* pixelator::StbImageDataView &operator = ( pixelator::StbImageDataView &&other
)
{
    if (this == &other)
    {
        return *this;
    }
    if (this->image_)
        stbi_image_free(this->image_);

    this->image_ = other.image_;
    this->size_of_image_.row = other->size_of_image_.row;
    this->size_of_image_.col = other.size_of_image_.col;
    this->channels_ = other.channels_;

    other.image_ = nullptr;
    other.size_of_image_.row = 0;
    other.size_of_image_.col = 0;
    other.channels_ = 0;

    return *this;
}; */

bool pixelator::StbImageDataView::empty() {
  if (this->size_of_image_.row == 0 && this->size_of_image_.col == 0) {
    return true;
  }
  return false;
}

pixelator::Size pixelator::StbImageDataView::size() {
  return this->size_of_image_;
}

int pixelator::StbImageDataView::rows() {
  int row = *this->size_of_image_.row;
  return row;
}
int pixelator::StbImageDataView::cols() {
  int col = *this->size_of_image_.col;
  return col;
}

ftxui::Color pixelator::StbImageDataView::at(int row, int col) {
  ftxui::Screen screen{
      ftxui::Screen(*this->size_of_image_.row, *this->size_of_image_.col)};
  screen.Print();
  auto &pixel = screen.PixelAt(row, col);
  auto color = pixel.foreground_color;
  return color;
}

pixelator::StbImageDataView::~StbImageDataView() {
  stbi_image_free(this->image_);
}
