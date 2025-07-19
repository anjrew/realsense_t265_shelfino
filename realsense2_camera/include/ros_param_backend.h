// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2022 Intel Corporation. All Rights Reserved.

#pragma once

#include <rclcpp/rclcpp.hpp>

namespace realsense2_camera
{
    class ParametersBackend
    {
    public:
        ParametersBackend(rclcpp::Node &node) : _node(node),
                                                _logger(node.get_logger()) {};
        ~ParametersBackend();

        // Use the modern callback type definition from rclcpp::Node.
        void add_on_set_parameters_callback(
            rclcpp::Node::OnSetParametersCallbackHandle::OnSetParametersCallbackType callback);

    private:
        rclcpp::Node &_node;
        rclcpp::Logger _logger;

        // The handle now has a specific, type-safe pointer.
        rclcpp::Node::OnSetParametersCallbackHandle::SharedPtr _ros_callback;
    };
}