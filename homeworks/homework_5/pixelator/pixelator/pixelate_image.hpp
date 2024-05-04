#ifndef PIXELATOR_PIXELATE_IMAGE_HPP
#define PIXELATOR_PIXELATE_IMAGE_HPP

#include <pixelator/image.hpp>
#include <pixelator/stb_image_data_view.hpp>

namespace pixelator {
int Scale(int number, float factor);
pixelator::Image PixelateImage(const pixelator::StbImageDataView& image,
                               pixelator::Size size);
}  // namespace pixelator

#endif /* PIXELATOR_PIXELATE_IMAGE_HPP */