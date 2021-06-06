[![LinkedIn][linkedin-shield]][linkedin-url]
<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


[![Github][github-shield]][github.com/zoumson?tab=repositories]
[![Stack Overflow][stackoverflow-shield]][stackoverflow.com/users/11175375/adam]
[![Leetcode][leetcode-shield]][eetcode.com/Hard_Code/]
-->
## Detection of a car license plate in a parking lot
![image](https://user-images.githubusercontent.com/38358621/120076768-da6dd780-c0d9-11eb-8723-8286ad1d293e.png)

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
      <a href="#file-structure">Files Structure</a>
      <ul>
        <li><a href="#folders">Folders</a></li>
        <li><a href="#entire-files-structure">Entire Files Structure</a></li>
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

<!--Built with -->
### Built With

<br>

* [opencv](https://opencv.org/)
* [cmake](https://cmake.org/)
* [gnu](https://www.gnu.org/)

<br>

## File Structure

### Folders

* [include/](include/): c++ header files.
* [resource/](resource/): xml and input images.
* [src/](src/): c++ definitions.


### Entire Files Structure 


```
.
├── CMakeLists.txt
├── include
│   ├── ConstantsDetectChars.h
│   ├── ConstantsDetectPlates.h
│   ├── ConstantsIdentifyPlate.h
│   ├── ConstantsPreprocess.h
│   ├── DetectChars.h
│   ├── DetectPlates.h
│   ├── IdentifyPlate.h
│   ├── PossibleChar.h
│   ├── PossiblePlate.h
│   ├── Preprocess.h
│   └── ShowLicensePlateArgs.h
├── README.md
├── ressource
│   ├── image
│   │   ├── image10.png
│   │   ├── image11.png
│   │   ├── image12.png
│   │   ├── image13.png
│   │   ├── image14.png
│   │   ├── image15.png
│   │   ├── image16.png
│   │   ├── image1.png
│   │   ├── image2.png
│   │   ├── image3.png
│   │   ├── image4.png
│   │   ├── image5.png
│   │   ├── image6.png
│   │   ├── image7.png
│   │   ├── image8.png
│   │   ├── image9.png
│   │   ├── imgOriginalScene.png
│   │   ├── test2.png
│   │   └── test.png
│   └── xml
│       ├── classifications.xml
│       └── images.xml
└── src
    ├── demo
    │   ├── CMakeLists.txt
    │   └── Demo.cpp
    └── lib
        ├── CMakeLists.txt
        └── plate
            ├── DetectChars.cpp
            ├── DetectPlates.cpp
            ├── IdentifyPlate.cpp
            ├── PossibleChar.cpp
            ├── PossiblePlate.cpp
            └── Preprocess.cpp

8 directories, 43 files

```


<!-- GETTING STARTED -->
## Getting Started

This is a sample code of how you may detect a license plate on a image.
To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* cmake
  ```sh
  sudo apt-get install cmake
  ```
 * CPP standard: `CMAKE_CXX_STANDARD 17`
 * [Install](https://askubuntu.com/questions/342202/failed-to-load-module-canberra-gtk-module-but-already-installed) `gtk` and `gtk3` module to access `canberra-gtk-module` used by `opencv imshow`
 
  ```sh
  sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
  ```

### Installation

1. Install first `opencv4` cpp libraries at [https://opencv.org/](https://opencv.org/)
2. Clone the repo
   ```sh
   git clone https://github.com/zoumson/LicensePlateDetection.git
   ```
3. Go to the project directory source
   ```sh
   cd LicensePlateDetection
   ```
4. Create empty directories `build`, `lib` and `bin`
   ```sh
   mkdir build && mkdir lib && mkdir bin && mkdir result && cd result && mkdir image && cd ..
   ```
5. Generate the library `libplate.so` and move it to `lib` and the exectutable `demo` and move it to `bin`
   ```sh
   cd build && cmake .. && make && cd ..
   ```
6. Install the library `libplate.so` to `/usr/lib` 
   ```sh
   cd build && sudo make install && cd ..
   ```   
<!-- USAGE EXAMPLES -->
### Usage
1. Command line arguments
<br>

```
Car license plate detection
Usage: demo [params] 

        -?, -h, --help, --usage (value:true)
                show help message
        -c, --classifier (value:./ressource/xml/classifications.xml)
                input classifier path
        --ext, -n (value:png)
                save image detected with detected plate extension
        -i, --image (value:<none>)
                input image path
        --name, -p (value:image)
                save image detected with detected plate name
        -p, --path (value:./result/image/)
                save image detected with detected plate path
        -s, --show (value:false)
                show detection steps
        --save, -v (value:false)
                save image with detected plate
        -t, --train (value:./ressource/xml/images.xml)
                input trained images path

```

<br>

2. Run with an image in `./ressource/image`
```
./bin/demo -i=./ressource/image/image6.png -v=true
```

<br>

## Before detection

 ![image6](https://user-images.githubusercontent.com/38358621/120063777-7cba9a80-c09b-11eb-8e14-82b2323ecd44.png)
 
 <br>
 
## After detection: image saved as `image_29_05_2021_16_25_27`

![image_29_05_2021_16_25_27](https://user-images.githubusercontent.com/38358621/120063750-4bda6580-c09b-11eb-8b9b-394f082a73a5.png)

<br>

## License plate number `NYSJ`
3. Back to the initial file structure configuration
   ```sh
   rm -r bin build lib result 
   ```
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

Project Link: [https://github.com/zoumson/LicensePlateDetection](https://github.com/zoumson/LicensePlateDetection.git)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Google](https://www.google.com/)
* [Stack Overflow](https://stackoverflow.com/)
* [Github](https://github.com/)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

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
[linkedin-url]: linkedin.com/in/adama-zouma-553bba13a
[product-screenshot]: images/screenshot.png

