/**
 * Copyright (c) 2018-2022, Ouster, Inc.
 * All rights reserved.
 *
 * @file point.h
 * @brief PCL point datatype for use with ouster sensors
 */

#pragma once

#include <pcl/point_types.h>

#include <Eigen/Core>
#include <chrono>

#include <ouster/lidar_scan.h>

namespace ouster_ros {

struct EIGEN_ALIGN16 Point {
    PCL_ADD_POINT4D;
    float intensity;
    uint32_t t;
    uint16_t reflectivity;
    uint8_t ring;
    uint16_t ambient;
    uint32_t range;
    // -----------------------------------------------
    // ADDED 2/14/23 TO TRACK INITIAL SCAN POSTION
    float vp_x;
    float vp_y;
    float vp_z;
    // -----------------------------------------------
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}  // namespace ouster_ros

// clang-format off
POINT_CLOUD_REGISTER_POINT_STRUCT(ouster_ros::Point,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, intensity, intensity)
    // use std::uint32_t to avoid conflicting with pcl::uint32_t
    (std::uint32_t, t, t)
    (std::uint16_t, reflectivity, reflectivity)
    (std::uint8_t, ring, ring)
    (std::uint16_t, ambient, ambient)
    (std::uint32_t, range, range)
    // -----------------------------------------------
    // ADDED 2/14/23 TO TRACK INITIAL SCAN POSTION
    (float, vp_x, vp_x)
    (float, vp_y, vp_y)
    (float, vp_z, vp_z)
    // -----------------------------------------------
)
// clang-format on
