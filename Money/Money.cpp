
#include "Money.h"

Money::Money() {
    this->RON1 = 50;
    this->RON5 = 40;
    this->RON10 = 30;
    this->RON20 = 20;
    this->RON50 = 20;
    this->RON100 = 20;
    this->RON200 = 10;
    this->RON500 = 5;
}


Money::Money(int RON1, int RON5, int RON10, int RON20, int RON50, int RON100, int RON200, int RON500) {
    this->RON1 = RON1;
    this->RON5 = RON5;
    this->RON10 = RON10;
    this->RON20 = RON20;
    this->RON50 = RON50;
    this->RON100 = RON100;
    this->RON200 = RON200;
    this->RON500 = RON500;
}

int Money::getRON1() {
    return this->RON1;
}

int Money::getRON5() {
    return this->RON5;
}

int Money::getRON10() {
    return this->RON10;
}

int Money::getRON20() {
    return this->RON20;
}

int Money::getRON50() {
    return this->RON50;
}

int Money::getRON100() {
    return this->RON100;
}

int Money::getRON200() {
    return this->RON200;
}

int Money::getRON500() {
    return this->RON500;
}

void Money::setRON1(int RON1) {
    this->RON1 = RON1;
}

void Money::setRON5(int RON5) {
    this->RON5 = RON5;
}

void Money::setRON10(int RON10) {
    this->RON10 = RON10;
}

void Money::setRON20(int RON20) {
    this->RON20 = getRON20();
}

void Money::setRON50(int RON50) {
    this->RON50 = RON50;
}

void Money::setRON100(int RON100) {
    this->RON100 = RON100;
}

void Money::setRON200(int RON200) {
    this->RON200 = RON200;
}

void Money::setRON500(int RON500) {
    this->RON500 = RON500;
}

Money &Money::operator=(const Money &money) {
    this->setRON1(money.RON1);
    this->setRON5(money.RON5);
    this->setRON10(money.RON10);
    this->setRON20(money.RON20);
    this->setRON50(money.RON50);
    this->setRON100(money.RON100);
    this->setRON200(money.RON200);
    this->setRON500(money.RON500);
}

bool Money::operator==(const Money &money) {
    return ((this->RON1 == money.RON1) and (this->RON5 == money.RON5) and (this->RON10 == money.RON10) and
    (this->RON20 == money.RON20) and (this->RON50 == money.RON50) and (this->RON100 == money.RON100) and
    (this->RON200 == money.RON200) and (this->RON500 == money.RON500));
}

Money::~Money() = default;




