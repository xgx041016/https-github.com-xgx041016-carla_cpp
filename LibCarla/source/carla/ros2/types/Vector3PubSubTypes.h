// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file Vector3PubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */

#ifndef _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_VECTOR3_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_VECTOR3_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>// 包含 Fast DDS 主题数据类型定义
#include <fastrtps/utils/md5.h>// 包含 MD5 工具以进行数据完整性检查

#include "Vector3.h"// 包含 Vector3 结构的定义

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)// 检查生成的 API 版本是否与预期版本匹配
#error \
    生成的 Vector3 与当前安装的 Fast DDS 不兼容。请使用 fastddsgen 重新生成。
#endif  // GEN_API_VER

namespace geometry_msgs
{
    namespace msg
    {

        #ifndef SWIG
        namespace detail {
// 模板结构用于辅助成员变量访问
            template<typename Tag, typename Tag::type M>
            struct Vector3_rob
            {
                friend constexpr typename Tag::type get(
                        Tag)
                {
                    return M;// 返回成员变量
                }
            };
// 用于访问 Vector3 的 z 组件的标签结构
            struct Vector3_f
            {
                typedef double Vector3::* type;// 定义类型为指向 Vector3 中 double 成员的指针
                friend constexpr type get(
                        Vector3_f);// 友元函数以访问该类型
            };
// Vector3 的 z 组件的特化
            template struct Vector3_rob<Vector3_f, &Vector3::m_z>;
// 获取 Vector3 结构中成员变量的偏移量
            template <typename T, typename Tag>
            inline size_t constexpr Vector3_offset_of() {
                return ((::size_t) &reinterpret_cast<char const volatile&>((((T*)0)->*get(Tag()))));
            }
        }
        #endif

        /*!  
         * @brief 此类表示用户在 IDL 文件中定义的 Vector3 类型的 TopicDataType。  
         * @ingroup VECTOR3  
         */ 
        class Vector3PubSubType : public eprosima::fastdds::dds::TopicDataType
        {
        public:

            typedef Vector3 type;// 定义类型为 Vector3

            eProsima_user_DllExport Vector3PubSubType();// 构造函数

            eProsima_user_DllExport virtual ~Vector3PubSubType() override;// 析构函数
// 将 Vector3 数据序列化为有效负载
            eProsima_user_DllExport virtual bool serialize(
                    void* data,
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;
// 将有效负载反序列化为 Vector3 数据
            eProsima_user_DllExport virtual bool deserialize(
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                    void* data) override;
// 提供序列化数据的大小
            eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
                    void* data) override;
// 获取 Vector3 实例的键
            eProsima_user_DllExport virtual bool getKey(
                    void* data,
                    eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                    bool force_md5 = false) override;
// 创建一个新的 Vector3 实例
            eProsima_user_DllExport virtual void* createData() override;
// 删除一个 Vector3 实例
            eProsima_user_DllExport virtual void deleteData(
                    void* data) override;

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED// 检查数据类型是否是有界的
            eProsima_user_DllExport inline bool is_bounded() const override
            {
                return true;// Vector3 是一个有界类型
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN// 检查数据类型是否是简单的
            eProsima_user_DllExport inline bool is_plain() const override
            {
                return is_plain_impl();// 调用实现检查是否简单
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

        #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE// 在提供的内存中构造 Vector3 的样本
            eProsima_user_DllExport inline bool construct_sample(
                    void* memory) const override
            {
                new (memory) Vector3();// 使用定位 new 构造 Vector3 
                return true;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
            MD5 m_md5;// 用于数据完整性的 MD5 哈希
            unsigned char* m_keyBuffer;// 键的缓冲区
        private:// 根据大小和布局检查 Vector3 类型是否简单
            static constexpr bool is_plain_impl()
            {
                return 24ULL == (detail::Vector3_offset_of<Vector3, detail::Vector3_f>() + sizeof(double));

            }};
    }
}

#endif // _FAST_DDS_GENERATED_GEOMETRY_MSGS_MSG_VECTOR3_PUBSUBTYPES_H_
