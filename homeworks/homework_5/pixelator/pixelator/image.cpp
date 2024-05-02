#include <pixelator/image.hpp>

pixelator::Image::Image(const int row,const int col):cols_{col}, rows_{row}, pixels_(row*col) {
  *size_.col = col, *size_.row = row;
  
}

bool pixelator::Image::empty() { return this->pixels_.empty(); }

int pixelator::Image::rows() { return this->rows_; }
int pixelator::Image::cols() { return this->cols_; }
pixelator::Size pixelator::Image::size() { return this->size_; }
ftxui::Color pixelator::Image::at(int row, int col) {
  return this->pixels_[cols_ * row + col];
}
pixelator::Image::~Image() {}