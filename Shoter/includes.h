#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <vector>
#include <iostream>

static const double DT = 0.1;

static const int MAP_SIZE_X = 1200;
static const int MAP_SIZE_Y = 800;

static const double HERO_RADIUS = 50;
static const double HERO_VELOCITY = 2;

static const double BULLET_VELOCITY = 5;
static const double BULLET_RADIUS = 5;