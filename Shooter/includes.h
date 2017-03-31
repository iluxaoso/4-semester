#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <vector>
#include <iostream>

static const double DT = 0.1;

static const int MAP_SIZE_X = 1000;
static const int MAP_SIZE_Y = 600;

static const double HERO_RADIUS = 64;
static const double HERO_VELOCITY = 2;

static const double BULLET_VELOCITY = 5;
static const double BULLET_RADIUS = 5;