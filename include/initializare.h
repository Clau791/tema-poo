//
// Created by klau2 on 10.04.2024.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <Camera.h>
#include <Hotel.h>
#ifndef OOP_INITIALIZARE_H
#define OOP_INITIALIZARE_H


Hotel hotel1("Grand Plaza");
CameraVIP cameraVip1(1, 500.0, true);
Camera camera1(101, "Dubla", 300.0);
Camera camera2(102, "Single", 150.0);
Camera camera3(103, "Dubla", 350.0, true);
Camera camera4(104, "Dubla", 370.0);
Camera camera5(105, "Dubla", 130.0, true);
hotel1.adaugaCamera(camera1);
hotel1.adaugaCamera(camera2);
hotel1.adaugaCamera(camera3);
hotel1.adaugaCamera(camera4);
hotel1.adaugaCamera(camera5);
hotel1.adaugaCamera(cameraVip1);


Hotel hotel2("Sea View");
Camera camera22(202, "Single", 180.0);
Camera camera23(203, "Dubla", 250.0, true);
Camera camera24(204, "Tripla", 450.0, true);
Camera camera25(205, "Tripla", 350.0);
hotel2.adaugaCamera(camera22);
hotel2.adaugaCamera(camera23);
hotel2.adaugaCamera(camera24);
hotel2.adaugaCamera(camera25);

Hotel hotel3("Grand Hotel");
Camera camera30(301, "Dubla", 320.0);
Camera camera31(302, "Single", 150.0);
Camera camera32(303, "Dubla", 350.0, true);
Camera camera33(304, "Dubla", 370.0, true);
Camera camera34(305, "Dubla", 330.0, true);
Camera camera35(305, "Tripla", 500.0);

hotel3.adaugaCamera(camera30);
hotel3.adaugaCamera(camera31);
hotel3.adaugaCamera(camera32);
hotel3.adaugaCamera(camera33);
hotel3.adaugaCamera(camera34);
hotel3.adaugaCamera(camera35);

// Crearea unui oraș si adaugarea hotelurilor în oraș
Oras oras1("Constanta");
Oras oras2("Bucuresti");
oras1.adaugaHotel(hotel1);
oras1.adaugaHotel(hotel2);
oras2.adaugaHotel(hotel3);



#endif //OOP_INITIALIZARE_H
