// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.
//设置一个类的声明，包含相关的头文件，并准备编译器生成必要的代码
#pragma once

#include "GameFramework/Actor.h"
#include "Carla/Weather/WeatherParameters.h"

#include "Weather.generated.h"

class ASensor;
class ASceneCaptureCamera;

UCLASS(Abstract)
class CARLA_API AWeather : public AActor
{
  GENERATED_BODY()
//定义了一个 AWeather 类的构造函数，接受一个 FObjectInitializer 类型的参数
public:

  AWeather(const FObjectInitializer& ObjectInitializer);

  /// 更新天气参数并将其通知到蓝图的事件
  UFUNCTION(BlueprintCallable)
  void ApplyWeather(const FWeatherParameters &WeatherParameters);

  /// 将天气通知到蓝图的事件
  void NotifyWeather(ASensor* Sensor = nullptr);

  /// 在不通知蓝图事件的情况下更新天气参数
  UFUNCTION(BlueprintCallable)
  void SetWeather(const FWeatherParameters &WeatherParameters);

  /// 返回当前的 天气参数 WeatherParameters
  UFUNCTION(BlueprintCallable)
  const FWeatherParameters &GetCurrentWeather() const
  {
    return Weather;
  }

  /// 返回昼夜循环是否有效（切换到夜间模式时自动 开/关 切换）
  UFUNCTION(BlueprintCallable)
  const bool &GetDayNightCycle() const
  {
    return DayNightCycle;
  }

  /// 更新昼夜周期
  void SetDayNightCycle(const bool &active);
//定义了一个受保护（protected）的成员函数 RefreshWeather，并通过 UFUNCTION(BlueprintImplementableEvent) 宏标记它为一个蓝图可实现事件
protected:

  UFUNCTION(BlueprintImplementableEvent)
  void RefreshWeather(const FWeatherParameters &WeatherParameters);
//一个类的私有成员定义部分，涉及天气系统中的一些功能，包括天气效果、后处理材质、以及与昼夜循环相关的设置
private:

  void CheckWeatherPostProcessEffects();

  UPROPERTY(VisibleAnywhere)
  FWeatherParameters Weather;

  UMaterial* PrecipitationPostProcessMaterial;

  UMaterial* DustStormPostProcessMaterial;

  TMap<UMaterial*, float> ActiveBlendables;

  UPROPERTY(EditAnywhere, Category = "Weather")
  bool DayNightCycle = true;
};
