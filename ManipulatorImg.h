#pragma once
#ifndef _MANIPULATION_H
#define _MANIPULATION_H

#include <iostream> 
#include <vector>
#include <dirent.h>
#include <stdexcept>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/ximgproc.hpp>

#include <cstdlib>



namespace processingImg {

	//******************************image*****************************

	class image {

	public:

		image() {} //construtores 

		image(cv::Mat image) { this->img = image; }

		image(char* path) { setImg(path); }

		bool emptyImg() { return this->img.empty(); }

		cv::Mat getImg() { return this->img; }

		void setImg(const char* path);

		void setImg(cv::Mat image) { this->img= image; }


		void imShow();

		void imWrite(std::string path, std::string name);


	private:
		cv::Mat img;
	};


		//********************** vector imgs **********************

	class imgContainer {

	public:
		//set caminho 
	
		imgContainer(std::string path) { this->path = path; this->addListImgs(); }

		imgContainer() {};

		bool setPath(char* path);

		std::string getPath();

		processingImg::image getImgInVector(int number);
		
		int sizeVector() { return imageVector.size(); }

		void addImgs(processingImg::image img);
	  

	private:

		std::string path= "-1";
		std::vector <image> imageVector;

		void addListImgs();

		std::vector <std::string> returnNamesImages();


		};



	//********************* imgManipulator *****************

	class imgManipulator {

		public:

			imgManipulator() {};

			imgManipulator(image img) {
				this->img = img;
			}

			void setImg(image img) {
				this->img = img;
			}


			imgManipulator applyImageThresholding(int min, int max, int type );

			imgManipulator applyImageAdaptativeTheresholding(int maxValue, int adaptiveMethods,int thresholdType, int blockSize,int C); 

			imgManipulator applyImageGaussianBlur(cv::Size ksize,double sigmaX, double sigmaY);

			imgManipulator applyImageMorphology(int elementStruc,int morph_size,int type,int iterations); 

			imgManipulator applyImageContrast(double alpha,double beta); 
		
			imgManipulator applyImageBlur(int ksize); 
			
			imgManipulator applyImageSubtract(image img); 

			imgManipulator applyImagemAdd(image img);

			imgManipulator applySuperPixels();

			imgManipulator applySubtractProtese(image img); 
			
			imgManipulator applyImageSegmentation2(); 
  
			imgManipulator applyImageSegmentation(); 

			imgManipulator applyImageCut(); 

			void calcArea(); 
		
			void calcAreaProtese(); 

			image build() {
				return this->img.getImg();
			}


		private:

			image img;
	
	};



}
#endif
