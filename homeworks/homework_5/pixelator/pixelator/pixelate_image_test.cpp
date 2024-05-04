#include <gtest/gtest.h>

#include <filesystem>
#include <pixelator/pixelate_image.hpp>
#include <string>
#include <vector>

// const std::filesystem::path
// image_path{"/home/erkam/Desktop/CppTuts/CodeForYourself/homeworks/homework5/pixelator/pixelator/test_data/test.png"};
const std::filesystem::path image_path{
    "../../pixelator/test_data/grumpy_little.png"};

TEST(PixelateImage, test1) {
  pixelator::Size s{98, 150};
  const pixelator::StbImageDataView image{image_path};
  const auto pixelated_image = pixelator::PixelateImage(image, s);

  bool empty = false;
  int row = 98;
  int col = 98;
  EXPECT_EQ(empty, pixelated_image.empty());
  EXPECT_EQ(row, pixelated_image.rows());
  EXPECT_EQ(col, pixelated_image.cols());

  const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};

  bool x = false;

  const pixelator::Image image_copy{pixelated_image};

  EXPECT_EQ(x, image_copy.at(4, 2) == yellowish);

  const pixelator::Image image_move{std::move(pixelated_image)};

  EXPECT_EQ(x, image_move.at(4, 2) == yellowish);
}