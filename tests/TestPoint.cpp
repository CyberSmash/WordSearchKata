//
// Created by jordan on 2/29/20.
//
#include "gtest/gtest.h"
#include "Point.hpp"

/**
 * Test that the constructor has no errors, and sets X and Y appropriately.
 */
TEST(PointTests, TestPointConstructor)
{
    std::unique_ptr<Point> p = nullptr;
    ASSERT_NO_THROW(p = std::make_unique<Point>(12, 8));
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 8);
}


/**
 * Test that getX and getY return sane values.
 *
 * This is effectively the sam as TestPointConstructor. They used to be different, but after
 * a refactor, the x and y properties became private, and getX and getY were used to get the values
 * of X and Y. This is kept for completeness and for historical rasons.
 */
TEST(PointTests, TestPointGetterXandY)
{
    std::unique_ptr<Point> p = std::make_unique<Point>(5, 2);

    ASSERT_EQ(p->getX(), 5);
    ASSERT_EQ(p->getY(), 2);
}

/**
 * Simple tests to ensure that calling that calling the individual setters
 * for each X and Y properly set those values and do not accidentally affect the
 * other.
 */
TEST(PointTests, TestPointSetterXandY)
{
    std::unique_ptr<Point> p = std::make_unique<Point>(5, 2);
    p->setX(12);
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 2);

    p->setY(44);
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 44);
}