// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "GameFramework/Actor.h"

#include "Traffic/RoutePlanner.h"
#include "Vehicle/VehicleSpawnPoint.h"

#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"


#include "OpenDriveActor.generated.h"

UCLASS()
class CARLA_API AOpenDriveActor : public AActor
{
  GENERATED_BODY()

protected:

  /// 用于存放图标精灵的UBillboardComponent
  UBillboardComponent *SpriteComponent;

  /// 雪碧用于广告牌组件
  UTexture2D *SpriteTexture;

private:

  UPROPERTY()
  TArray<AVehicleSpawnPoint *> VehicleSpawners;

#if WITH_EDITORONLY_DATA
  /// 使用OpenDrive文件（命名为current.umap）生成道路网络
  UPROPERTY(Category = "Generate", EditAnywhere)
  bool bGenerateRoutes = false;
#endif // WITH_EDITORONLY_DATA

  /// 汽车行驶的路点之间的距离
  UPROPERTY(Category = "Generate", EditAnywhere, meta = (ClampMin = "0.01", UIMin = "0.01"))
  float RoadAccuracy = 2.f;

  /// 触发相关
  UPROPERTY(Category = "Generate", EditAnywhere, meta = (ClampMin = "0.01", UIMin = "0.01"))
  float TriggersHeight = 100.f;

#if WITH_EDITORONLY_DATA
  /// 删除之前生成的道路网络。此外，如有必要，它还将删除产卵者
  UPROPERTY(Category = "Generate", EditAnywhere)
  bool bRemoveRoutes = false;
#endif // WITH_EDITORONLY_DATA

  /// 如果为真，生成路线时将放置产卵者
  UPROPERTY(Category = "Spawners", EditAnywhere)
  bool bAddSpawners = false;

  /// 如果情况属实，产卵者也将被安置在路口
  UPROPERTY(Category = "Spawners", EditAnywhere)
  bool bOnIntersections = false;

  /// 确定产卵器相对于每个RoutePlanner的放置高度
  UPROPERTY(Category = "Spawners", EditAnywhere)
  float SpawnersHeight = 300.f;

#if WITH_EDITORONLY_DATA
  /// 必要时删除已放置的产卵器
  UPROPERTY(Category = "Spawners", EditAnywhere)
  bool bRemoveCurrentSpawners = false;
#endif // WITH_EDITORONLY_DATA

#if WITH_EDITORONLY_DATA
  /// 显示/隐藏其他调试信息
  UPROPERTY(Category = "Debug", EditAnywhere)
  bool bShowDebug = true;
#endif // WITH_EDITORONLY_DATA

public:

  AOpenDriveActor(const FObjectInitializer &ObjectInitializer);

  void BuildRoutes();

  void BuildRoutes(FString MapName);

  /// 删除此类以前生成的所有现有ARoutePlanner和VehicleSpawner，以避免重叠
  void RemoveRoutes();

  void DebugRoutes() const;

  void RemoveDebugRoutes() const;

#if WITH_EDITOR
  void PostEditChangeProperty(struct FPropertyChangedEvent &PropertyChangedEvent);

#endif // WITH_EDITOR

  void AddSpawners();

  void RemoveSpawners();

  UPROPERTY()
  TArray<ARoutePlanner *> RoutePlanners;
};
