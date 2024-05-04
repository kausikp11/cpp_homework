#include <pixelator/drawer.hpp>

pixelator::Drawer::Drawer(ftxui::Dimensions dimension) {
  if (dimension.dimx == ftxui::Dimension::Full().dimx &&
      dimension.dimy == ftxui::Dimension::Full().dimy) {
    row_ = dimension.dimy;
    col_ = dimension.dimx;
  } else {
    row_ = dimension.dimy;
    col_ = row_ * 2;
  }
  screen_ = ftxui::Screen::Create(dimension);
}

int pixelator::Drawer::cols() const { return this->col_; }
int pixelator::Drawer::rows() const { return this->row_; }
pixelator::Size pixelator::Drawer::size() const {
  return pixelator::Size{rows(), cols()};
}
void pixelator::Drawer::Set(const Image& image) {
  int a = 2;
  for (int i = 0; i < image.cols(); i = i + a) {
    for (int j = 0; j < image.rows(); j++) {
      for (int k = 0; k < a; k++) {
        for (int t = 0; t < a; t++) {
          screen_.PixelAt(i + t, j + k).background_color = image.at(j, i);
          screen_.PixelAt(i + t, j + k).character = ' ';
        }
      }
    }
  }
}

void pixelator::Drawer::Draw() { screen_.Print(); }

std::string pixelator::Drawer::ToString() const { return screen_.ToString(); }