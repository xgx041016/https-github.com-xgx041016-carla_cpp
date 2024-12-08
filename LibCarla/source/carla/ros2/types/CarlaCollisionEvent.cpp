﻿// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file CarlaCarlaCollisionEvent.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32
// 包含 CarlaCollisionEvent 类的头文件
#include "CarlaCollisionEvent.h"
// 包含 FastCDR 库中用于序列化和反序列化操作的 Cdr 类的头文件
#include <fastcdr/Cdr.h>
// 包含 FastCDR 库中异常相关的头文件，用于处理参数异常等情况
#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

#define carla_msgs_msg_geometry_msgs_msg_Vector3_max_cdr_typesize 24ULL;
#define carla_msgs_msg_std_msgs_msg_Header_max_cdr_typesize 268ULL;
#define carla_msgs_msg_CarlaCollisionEvent_max_cdr_typesize 296ULL;
#define carla_msgs_msg_std_msgs_msg_Time_max_cdr_typesize 8ULL;
#define carla_msgs_msg_geometry_msgs_msg_Vector3_max_key_cdr_typesize 0ULL;
#define carla_msgs_msg_std_msgs_msg_Header_max_key_cdr_typesize 0ULL;
#define carla_msgs_msg_CarlaCollisionEvent_max_key_cdr_typesize 0ULL;
#define carla_msgs_msg_std_msgs_msg_Time_max_key_cdr_typesize 0ULL;
// CarlaCollisionEvent 类的默认构造函数，用于初始化对象
carla_msgs::msg::CarlaCollisionEvent::CarlaCollisionEvent()
{
    // std_msgs::msg::Header m_header
    // unsigned long m_other_actor_id
    m_other_actor_id = 0;
    // geometry_msgs::msg::Vector3 m_normal_impulse
}
// CarlaCollisionEvent 类的析构函数，用于释放对象占用的资源等清理操作
carla_msgs::msg::CarlaCollisionEvent::~CarlaCollisionEvent()
{
}
// 拷贝构造函数，用于通过已有对象来创建一个新的相同类型的对象，并进行深拷贝
carla_msgs::msg::CarlaCollisionEvent::CarlaCollisionEvent(
        const CarlaCollisionEvent& x)
{
    m_header = x.m_header;
    m_other_actor_id = x.m_other_actor_id;
    m_normal_impulse = x.m_normal_impulse;
}
// 移动构造函数，利用移动语义高效地“窃取”传入对象 x 的资源，避免不必要的拷贝操作
carla_msgs::msg::CarlaCollisionEvent::CarlaCollisionEvent(
        CarlaCollisionEvent&& x) noexcept
{
    m_header = std::move(x.m_header);
    m_other_actor_id = x.m_other_actor_id;
    m_normal_impulse = std::move(x.m_normal_impulse);
}
// 重载赋值运算符（拷贝赋值），用于将一个已有对象的值赋给另一个同类型的对象，实现深拷贝赋值操作
carla_msgs::msg::CarlaCollisionEvent& carla_msgs::msg::CarlaCollisionEvent::operator =(
        const CarlaCollisionEvent& x)
{
    m_header = x.m_header;
    m_other_actor_id = x.m_other_actor_id;
    m_normal_impulse = x.m_normal_impulse;

    return *this;
}
// 重载赋值运算符（移动赋值），利用移动语义高效地将传入对象 x 的资源转移给当前对象，避免深拷贝开销
carla_msgs::msg::CarlaCollisionEvent& carla_msgs::msg::CarlaCollisionEvent::operator =(
        CarlaCollisionEvent&& x) noexcept
{
    m_header = std::move(x.m_header);
    m_other_actor_id = x.m_other_actor_id;
    m_normal_impulse = std::move(x.m_normal_impulse);

    return *this;
}
// 重载相等运算符，用于比较两个 CarlaCollisionEvent 对象是否相等
bool carla_msgs::msg::CarlaCollisionEvent::operator ==(
        const CarlaCollisionEvent& x) const
{
    return (m_header == x.m_header && m_other_actor_id == x.m_other_actor_id && m_normal_impulse == x.m_normal_impulse);
}
// 重载不等运算符，通过对相等运算符结果取反来判断两个对象是否不相等
bool carla_msgs::msg::CarlaCollisionEvent::operator !=(
        const CarlaCollisionEvent& x) const
{
    return !(*this == x);
}
// 获取该消息类型在 CDR 序列化时的最大尺寸
size_t carla_msgs::msg::CarlaCollisionEvent::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return carla_msgs_msg_CarlaCollisionEvent_max_cdr_typesize;
}
// 获取给定的 CarlaCollisionEvent 对象在当前对齐要求下的 CDR 序列化后的实际尺寸
size_t carla_msgs::msg::CarlaCollisionEvent::getCdrSerializedSize(
        const carla_msgs::msg::CarlaCollisionEvent& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;
    current_alignment += std_msgs::msg::Header::getCdrSerializedSize(data.header(), current_alignment);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    current_alignment += geometry_msgs::msg::Vector3::getCdrSerializedSize(data.normal_impulse(), current_alignment);
    return current_alignment - initial_alignment;
}
// 将当前 CarlaCollisionEvent 对象进行 CDR 序列化，即将对象的各个成员变量按照 CDR 格式依次写入到传入的 Cdr 对象 scdr 中
void carla_msgs::msg::CarlaCollisionEvent::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    scdr << m_header;
    scdr << m_other_actor_id;
    scdr << m_normal_impulse;
}
// 对传入的 Cdr 对象 dcdr 中的数据进行反序列化，将数据读取出来并赋值给当前对象的各个成员变量，按照 CDR 格式解析出对象的原始状态
void carla_msgs::msg::CarlaCollisionEvent::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{
    dcdr >> m_header;
    dcdr >> m_other_actor_id;
    dcdr >> m_normal_impulse;
}

/*!
 * @brief This function copies the value in member header
 * @param _header New value to be copied in member header
 */// 设置成员变量 m_header 的值，通过拷贝传入的 _header 对象的值来更新当前对象的 m_header 成员变量
void carla_msgs::msg::CarlaCollisionEvent::header(
        const std_msgs::msg::Header& _header)
{
    m_header = _header;
}

/*!
 * @brief This function moves the value in member header
 * @param _header New value to be moved in member header
 */// 通过移动语义来设置成员变量 m_header 的值，将传入的 _header 对象的资源转移给当前对象的 m_header 成员变量
void carla_msgs::msg::CarlaCollisionEvent::header(
        std_msgs::msg::Header&& _header)
{
    m_header = std::move(_header);
}

/*!
 * @brief This function returns a constant reference to member header
 * @return Constant reference to member header
 */// 返回成员变量 m_header 的常量引用，用于在不允许修改该成员变量的场景下获取其值进行访问操作
const std_msgs::msg::Header& carla_msgs::msg::CarlaCollisionEvent::header() const
{
    return m_header;
}

/*!
 * @brief This function returns a reference to member header
 * @return Reference to member header
 */// 返回成员变量 m_header 的普通引用，可用于在允许修改该成员变量的场景下获取其值进行访问和修改操作
std_msgs::msg::Header& carla_msgs::msg::CarlaCollisionEvent::header()
{
    return m_header;
}

/*!
 * @brief This function sets a value in member other_actor_id
 * @param _other_actor_id New value for member other_actor_id
 */// 设置成员变量 m_other_actor_id 的值，将传入的 _other_actor_id 参数值赋给当前对象的该成员变量
void carla_msgs::msg::CarlaCollisionEvent::other_actor_id(
        uint32_t _other_actor_id)
{
    m_other_actor_id = _other_actor_id;
}

/*!
 * @brief This function returns the value of member other_actor_id
 * @return Value of member other_actor_id
 */// 返回成员变量 m_other_actor_id 的值，用于获取该成员变量存储的数值
uint32_t carla_msgs::msg::CarlaCollisionEvent::other_actor_id() const
{
    return m_other_actor_id;
}

/*!
 * @brief This function returns a reference to member other_actor_id
 * @return Reference to member other_actor_id
 */// 返回成员变量 m_other_actor_id 的引用，可用于获取其值进行访问或者修改操作
uint32_t& carla_msgs::msg::CarlaCollisionEvent::other_actor_id()
{
    return m_other_actor_id;
}

/*!
 * @brief This function copies the value in member normal_impulse
 * @param _normal_impulse New value to be copied in member normal_impulse
 */// 通过拷贝传入的 _normal_impulse 对象的值来设置成员变量 m_normal_impulse 的值
void carla_msgs::msg::CarlaCollisionEvent::normal_impulse(
        const geometry_msgs::msg::Vector3& _normal_impulse)
{
    m_normal_impulse = _normal_impulse;
}

/*!
 * @brief This function moves the value in member normal_impulse
 * @param _normal_impulse New value to be moved in member normal_impulse
 */// 通过移动语义来设置成员变量 m_normal_impulse 的值，将传入的 _normal_impulse 对象的资源转移给该成员变量
void carla_msgs::msg::CarlaCollisionEvent::normal_impulse(
        geometry_msgs::msg::Vector3&& _normal_impulse)
{
    m_normal_impulse = std::move(_normal_impulse);
}

/*!
 * @brief This function returns a constant reference to member normal_impulse
 * @return Constant reference to member normal_impulse
 */// 返回成员变量 m_normal_impulse 的常量引用，用于在不允许修改该成员变量的情况下获取其值进行访问操作
const geometry_msgs::msg::Vector3& carla_msgs::msg::CarlaCollisionEvent::normal_impulse() const
{
    return m_normal_impulse;
}

/*!
 * @brief This function returns a reference to member normal_impulse
 * @return Reference to member normal_impulse
 */// 返回成员变量 m_normal_impulse 的普通引用，可用于获取其值进行访问和修改操作
geometry_msgs::msg::Vector3& carla_msgs::msg::CarlaCollisionEvent::normal_impulse()
{
    return m_normal_impulse;
}
// 获取该消息类型用于作为键进行 CDR 序列化时的最大尺寸，这里简单返回预定义的最大值，忽略传入的当前对齐参数
size_t carla_msgs::msg::CarlaCollisionEvent::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return carla_msgs_msg_CarlaCollisionEvent_max_key_cdr_typesize;
}
// 判断该消息类型是否定义了键，这里返回 false，表示没有定义键
bool carla_msgs::msg::CarlaCollisionEvent::isKeyDefined()
{
    return false;
}
// 对当前对象按照键的 CDR 序列化要求进行序列化操作，这里目前为空实现
void carla_msgs::msg::CarlaCollisionEvent::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}
