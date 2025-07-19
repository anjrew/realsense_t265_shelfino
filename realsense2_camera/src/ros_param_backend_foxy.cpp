#include "ros_param_backend.h"

namespace realsense2_camera
{
    void ParametersBackend::add_on_set_parameters_callback(
        rclcpp::Node::OnSetParametersCallbackHandle::OnSetParametersCallbackType callback)
    {
        _ros_callback = _node.add_on_set_parameters_callback(callback);
    }

    ParametersBackend::~ParametersBackend()
    {
        // The callback is automatically deregistered when _ros_callback goes out of scope.
        // The destructor can be empty.
    }
}