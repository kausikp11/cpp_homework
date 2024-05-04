#ifndef PIXELATOR_DRAWER_HPP
#define PIXELATOR_DRAWER_HPP

#include <ftxui/screen/screen.hpp>
#include <pixelator/image.hpp>
#include <pixelator/stb_image_data_view.hpp>

namespace pixelator {
class Drawer {
 private:
  ftxui::Screen screen_{0, 0};
  int row_;
  int col_;

 public:
  Drawer() = default;
  explicit Drawer(ftxui::Dimensions dimension);
  int rows() const;
  int cols() const;
  pixelator::Size size() const;
  void Set(const Image& image);
  void Draw();
  std::string ToString() const;
};
}  // namespace pixelator

#endif /* PIXELATOR_DRAWER_HPP */