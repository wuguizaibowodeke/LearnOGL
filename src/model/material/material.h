#pragma once
#include "base/core.h"

//ʹ��C++��ö������
enum class MaterialType {
	PhongMaterial
};

class Material {
public:
	Material();
	~Material();

public:
	MaterialType mType;
};