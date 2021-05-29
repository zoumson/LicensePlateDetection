<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
-->


<!-- PROJECT LOGO -->
<!-- 
<br />
<p align="center">

  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>
<p align="center">
  <h3 align="center">Best-README-Template</h3>

  <p align="center">
    An awesome README template to jumpstart your projects!
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues">Report Bug</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues">Request Feature</a>
  </p>
</p>
-->


<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

LPR (License Plate Recognition), also known as ANPR (Automatic Number-Plate Recognition) is an image-processing technology used to identify vehicles by their license plates.

The system uses illumination and an infrared camera to take the image of the front or rear of the vehicle, then an image-processing software analyzes the images and extracts the license plate information.

Here's why LDR is valuable:

* First of all, safety: the license plate serves as a virtual ticket, and grants free-flow access, preventing stolen cars or ticket swapping. Since ticket and license plate have to match at entry and exit, it is almost impossible to pursue fraudulent behaviors. With LPR you can also easily manage black lists and be in control of all the events and movements at entrance and exit.

* LPR is highly reliable: in case of lost tickets, it is easy to determine the actual entry time from the license plate number.

* In addition, LPR also allows multiple integrations and customizations, especially for contract parking where the recurrent user can smoothly access and egress the car park without any titles other than the vehicle license plate.

* With LPR, it is also possible to enter with a pre-paid ticket, or use cashless solutions. Another benefit offered by LPR at entries/exits is the possibility to book a parking space in advance, to ensure the driver a hassle-free experience.

* Last but not least, LPR can be retrofitted and added to existing solutions.

A list of commonly used resources that I find helpful are listed in the acknowledgements.

### Built With


* [opencv](https://opencv.org/)
* [cmake](https://cmake.org/)
* [gnu](https://www.gnu.org/)



<!-- GETTING STARTED -->
## Getting Started

This is an sample code of how you may detect a license plate on a image.
To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* cmake
  ```sh
  sudo apt-get install cmake
  ```
 * CPP standard: `CMAKE_CXX_STANDARD 17`

### Installation

1. Install first `opencv4` cpp libraries at [https://opencv.org/](https://opencv.org/)
2. Clone the repo
   ```sh
   git clone https://github.com/zoumson/ParkingLotLicensePlateDetectionOpencv.git
   ```
3. Go to build
   ```sh
   cd ./build
   ```
4. Then run the cmake file to generate the makefile
   ```sh
   cmake ..
   ```
5. Finally run the makefile to generate the executable `plate`
   ```sh
   make
   ```


<!-- USAGE EXAMPLES -->
### Usage
1. Command line arguments
<br>

```
Car license plate detection
Usage: plate [params] 

	-?, -h, --help, --usage (value:true)
		show help message
	-c, --classifier (value:../ressource/xml/classifications.xml)
		input classifier path
	--ext, -n (value:png)
		save image detected with detected plate extension
	-i, --image (value:<none>)
		input image path
	--name, -p (value:image)
		save image detected with detected plate name
	-p, --path (value:../result/image/)
		save image detected with detected plate path
	-s, --show (value:false)
		show detection steps
	--save, -v (value:false)
		save image with detected plate
	-t, --train (value:../ressource/xml/images.xml)
		input trained images path

```


2. Run with an image in `ressource/image`
```
./plate -i=../ressource/image/image6.png -v=true
```



## * Before detection

 ![image6](https://user-images.githubusercontent.com/38358621/120063777-7cba9a80-c09b-11eb-8e14-82b2323ecd44.png)
 
 
## * After detection: image saved as `image_29_05_2021_16_25_27`, current date and time is appended

![image_29_05_2021_16_25_27](https://user-images.githubusercontent.com/38358621/120063750-4bda6580-c09b-11eb-8b9b-394f082a73a5.png)

<!-- ROADMAP -->
## Roadmap

All the headers files are well docummented, read through the comments



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Adama Zouma - <!-- [@your_twitter](https://twitter.com/your_username) -->- stargue49@gmail.com

Project Link: [https://github.com/zoumson/ParkingLotLicensePlateDetectionOpencv](https://github.com/zoumson/ParkingLotLicensePlateDetectionOpencv)



<!-- ACKNOWLEDGEMENTS -->
<!-- 
## Acknowledgements
* [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
* [Img Shields](https://shields.io)
* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Pages](https://pages.github.com)
* [Animate.css](https://daneden.github.io/animate.css)
* [Loaders.css](https://connoratherton.com/loaders)
* [Slick Carousel](https://kenwheeler.github.io/slick)
* [Smooth Scroll](https://github.com/cferdinandi/smooth-scroll)
* [Sticky Kit](http://leafo.net/sticky-kit)
* [JVectorMap](http://jvectormap.com)
* [Font Awesome](https://fontawesome.com)
-->




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
<!-- 
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
-->
