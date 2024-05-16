#include <opencv2/opencv.hpp>
#include <iostream>
 
int main() {
    // 读取图像
    cv::Mat img = cv::imread("/home/xuen/桌面/rm/week-11/pt/a.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "图像加载失败" << std::endl;
        return -1;
    }
    else  std::cout<<"ok";
 
    // 创建一个窗口显示图像
    cv::namedWindow("原始图像", cv::WINDOW_AUTOSIZE);
    cv::imshow("原始图像", img);
 
    // 使用Canny算法检测边缘
    cv::Mat edges;
    double lowerThreshold = 50; // 下限阈值
    double upperThreshold = 150; // 上限阈值
    int apertureSize = 3;        // 应用Sobel算子的窗口大小
    cv::Canny(img, edges, lowerThreshold, upperThreshold, apertureSize);
 
    // 创建一个窗口显示边缘检测结果
    cv::namedWindow("边缘检测结果", cv::WINDOW_AUTOSIZE);
    cv::imshow("边缘检测结果", edges);
 
    // 等待按键事件
    cv::waitKey(0);
 
    return 0;
}