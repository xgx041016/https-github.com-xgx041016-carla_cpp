// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

<<<<<<< HEAD
#pragma once  // 确保该头文件仅被包含一次

#include "carla/Buffer.h"  // 包含 Buffer 类的定义

#include <rpc/msgpack.hpp>  // 包含 MessagePack 的头文件
=======
#pragma once
#include "carla/Buffer.h" // 引入 Buffer 头文件，Buffer 类用于处理数据缓冲区
#include <rpc/msgpack.hpp> // 引入 MessagePack 库头文件
>>>>>>> 6816e65ac738db61e2602198a3d0c8188b71f21c

namespace carla {  // carla 命名空间

  class MsgPack {  // MsgPack 类定义
  public:

<<<<<<< HEAD
    // 模板方法，序列化对象 obj 为 Buffer 类型
    template <typename T>
    static Buffer Pack(const T &obj) {
      namespace mp = ::clmdep_msgpack;  // 为 MessagePack 命名空间起别名

      mp::sbuffer sbuf;  // 创建一个 MessagePack 的缓冲区对象
      mp::pack(sbuf, obj);  // 使用 MessagePack 序列化对象 obj 到 sbuf 中

      // 将 sbuf 中的数据和大小封装到 Buffer 对象中并返回
      return Buffer(reinterpret_cast<const unsigned char *>(sbuf.data()), sbuf.size());
    }

    // 模板方法，从 Buffer 对象反序列化为对象 T
    template <typename T>
    static T UnPack(const Buffer &buffer) {
      namespace mp = ::clmdep_msgpack;  // 为 MessagePack 命名空间起别名

      // 使用 MessagePack 从 Buffer 中的数据反序列化为对象 T
      return mp::unpack(reinterpret_cast<const char *>(buffer.data()), buffer.size()).template as<T>();
    }

    // 模板方法，从原始数据（unsigned char *）和大小反序列化为对象 T
    template <typename T>
    static T UnPack(const unsigned char *data, size_t size) {
      namespace mp = ::clmdep_msgpack;  // 为 MessagePack 命名空间起别名

      // 使用 MessagePack 从原始数据反序列化为对象 T
      return mp::unpack(reinterpret_cast<const char *>(data), size).template as<T>();
    }
  };

} // namespace carla

=======
    // 模板方法，将对象 obj 序列化为 Buffer
    template <typename T>
    static Buffer Pack(const T &obj) {
      namespace mp = ::clmdep_msgpack; // 使用自定义命名空间 clmdep_msgpack
      mp::sbuffer sbuf; // 创建一个 MessagePack 的缓冲区对象 sbuf
      mp::pack(sbuf, obj); // 使用 MessagePack 的 pack 方法将对象 obj 序列化到 sbuf 中
      // 构造 Buffer 对象，将 sbuf 的数据和大小传递给 Buffer
      return Buffer(reinterpret_cast<const unsigned char *>(sbuf.data()), sbuf.size());
    }

    // 模板方法，将 Buffer 反序列化为对象 T
    template <typename T>
    static T UnPack(const Buffer &buffer) {
      namespace mp = ::clmdep_msgpack; // 使用自定义命名空间 clmdep_msgpack
      // 使用 MessagePack 的 unpack 方法将 Buffer 中的数据反序列化为对象 T
      // reinterpret_cast 用于将 unsigned char* 类型的 data 转换为 char* 类型
      return mp::unpack(reinterpret_cast<const char *>(buffer.data()), buffer.size()).template as<T>();
    }

    // 模板方法，将原始数据反序列化为对象 T
    template <typename T>
    static T UnPack(const unsigned char *data, size_t size) {
      namespace mp = ::clmdep_msgpack; // 使用自定义命名空间 clmdep_msgpack
      // 使用 MessagePack 的 unpack 方法将原始数据反序列化为对象 T
      // reinterpret_cast 用于将 unsigned char* 类型的 data 转换为 char* 类型
      return mp::unpack(reinterpret_cast<const char *>(data), size).template as<T>();
    }
  };
>>>>>>> 6816e65ac738db61e2602198a3d0c8188b71f21c
