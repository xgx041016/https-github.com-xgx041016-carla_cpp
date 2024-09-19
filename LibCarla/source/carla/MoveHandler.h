// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

<<<<<<< HEAD
#pragma once  // 确保头文件只被包含一次

#include <type_traits>  // 包含类型特性库，用于类型特性相关的工具
#include <utility>  //  包含实用工具库，提供 std::move 等功能

namespace carla {  // 定义命名空间 carla
namespace detail {   //  定义命名空间 detail，用于实现细节

  template <typename FunctorT>  // 模板声明，接受任意类型 FunctorT
  struct MoveWrapper : FunctorT {// 定义 MoveWrapper 结构，继承自 FunctorT
    MoveWrapper(FunctorT &&f) : FunctorT(std::move(f)) {}
=======
#pragma once  // 纭繚姝ゅご鏂囦欢浠呰鍖呭惈涓�娆�

#include <type_traits>  // 鍖呭惈绫诲瀷鐗瑰緛鐩稿叧鐨勫ご鏂囦欢锛屾彁渚涚被鍨嬬壒鎬ф敮鎸�
#include <utility>  // 鍖呭惈閫氱敤宸ュ叿鍑芥暟锛屾瘮濡� std::move

namespace carla {  // 瀹氫箟鍛藉悕绌洪棿 carla
namespace detail {   // 瀹氫箟鍛藉悕绌洪棿 detail锛岀敤浜庡疄鐜扮粏鑺�

  template <typename FunctorT>  // 瀹氫箟涓�涓ā鏉跨粨鏋勪綋锛屾帴鍙椾换鎰忕被鍨� FunctorT
  struct MoveWrapper : FunctorT {  // MoveWrapper 缁ф壙鑷� FunctorT
    MoveWrapper(FunctorT &&f) : FunctorT(std::move(f)) {}  // 鏋勯�犲嚱鏁帮紝绉诲姩鏋勯�� FunctorT
>>>>>>> 6bf499bf364e66adc2c81feba27503c6e62f698e

    MoveWrapper(MoveWrapper &&) = default;  // 绉诲姩鏋勯�犲嚱鏁帮紝浣跨敤榛樿瀹炵幇
    MoveWrapper& operator=(MoveWrapper &&) = default;  // 绉诲姩璧嬪�艰繍绠楃锛屼娇鐢ㄩ粯璁ゅ疄鐜�

    MoveWrapper(const MoveWrapper &);  // 澹版槑澶嶅埗鏋勯�犲嚱鏁帮紙鏈畾涔夛級
    MoveWrapper& operator=(const MoveWrapper &);  // 澹版槑澶嶅埗璧嬪�艰繍绠楃锛堟湭瀹氫箟锛�
  };

} // namespace detail

  /// Hack to trick asio into accepting move-only handlers, if the handler were
  /// actually copied it would result in a link error.
  ///
  /// @see https://stackoverflow.com/a/22891509.
  template <typename FunctorT>  // 瀹氫箟涓�涓ā鏉垮嚱鏁帮紝鎺ュ彈浠绘剰绫诲瀷 FunctorT
  auto MoveHandler(FunctorT &&func) {   // MoveHandler 鍑芥暟杩斿洖涓�涓Щ鍔ㄥ鐞嗗櫒
    using F = typename std::decay<FunctorT>::type;  // 浣跨敤 std::decay 澶勭悊 FunctorT 鐨勭被鍨�
    return detail::MoveWrapper<F>{std::move(func)};   // 杩斿洖涓�涓� MoveWrapper 瀹炰緥锛岀Щ鍔ㄤ紶鍏ョ殑 func
  }

} // namespace carla
