#include "image.h"
#include "definitions.hpp"
#include <string>

#define BOOST_TEST_MODULE Test_Make_Panorama
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace std;


BOOST_AUTO_TEST_CASE(test_structure)
  {
  Image im = load_image(ROOT_DIR / "data/dogbw.png");
  Image s = structure_matrix(im, 2);
  s.feature_normalize_total();
  save_png(s, ROOT_DIR / "output/structure");
  Image gt = load_image(ROOT_DIR / "data/structure.png");
  
  BOOST_TEST(same_image(s, gt));
  }

BOOST_AUTO_TEST_CASE(test_cornerness)
  {
  Image im = load_image(ROOT_DIR / "data/dogbw.png");
  Image s = structure_matrix(im, 2);
  Image c = cornerness_response(s,0);
  c.feature_normalize_total();
  save_png(c, ROOT_DIR / "output/response");
  Image gt = load_image(ROOT_DIR / "data/response.png");
  BOOST_TEST(same_image(c, gt));
  }


