//
// Created by thomas on 12/16/25.
//
#include "image.h"
#include "definitions.hpp"
#include "../../config/definitions.hpp"

int main(int argc, char **argv)
{

    Image a = load_image(ROOT_DIR / "pano/rainier/Rainier1.png");
    Image b = load_image(ROOT_DIR / "pano/rainier/Rainier2.png");

    Image corners=detect_and_draw_corners(a, 2, 0.4, 5, 3, 0);
    save_image(corners, ROOT_DIR / "output/corners");

    vector<Descriptor> ad=harris_corner_detector(a, 2, 0.4, 5, 3, 0);
    vector<Descriptor> bd=harris_corner_detector(b, 2, 0.4, 5, 3, 0);

    vector<Match> match=match_descriptors(ad,bd);
    Image inliers=draw_inliers(a,b,RANSAC(match,5,10000,50),match,5);

    Image m = find_and_draw_matches(a, b, 2, 0.4, 7, 3, 0);
    Image pan=panorama_image(a,b,2,0,0.3,7,3,5,1000,50,0.5);

    save_image(m, ROOT_DIR / "output/matches");
    save_image(inliers, ROOT_DIR / "output/inliers");
    save_image(pan, ROOT_DIR / "output/easy_panorama");

    save_image(panorama_image(cylindrical_project(a,500),cylindrical_project(b,500),2,0,0.3,7,3,5,1000,50,0.5), "output/easy_panorama_cyl");
    save_image(panorama_image(spherical_project(a,500),spherical_project(b,500),2,0,0.3,7,3,5,1000,50,0.5), "output/easy_panorama_sphere");


    return 0;
}
