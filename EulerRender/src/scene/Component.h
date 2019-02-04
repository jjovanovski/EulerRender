#pragma once

#include <vector>

#include "../API.h"
#include "../math/Vec3.h"
#include "../math/Quaternion.h"
#include "../math/Transformation.h"

namespace Euler {

	class EULER_API Component {
	private:
		Component * parent = nullptr;
		std::vector<Component*> children;

		Vec3 position;
		Quaternion rotation;
		Vec3 scale;

	protected:
		Vec3 worldPosition;
		Quaternion worldRotation;
		Vec3 worldScale;

		Mat4 modelMatrix;

		void UpdateComponent();
		void DrawComponent();
		virtual void Update() {};
		virtual void Draw() {};

		void UpdateModelMatrix();

	public:
		Component();
		virtual ~Component();

		void AddChild(Component * component);

		Vec3 Forward();
		Vec3 Right();
		Vec3 Up();

		Mat4 GetModelMatrix();

		void UpdateWorldPosition();
		void UpdateWorldRotation();
		void UpdateWorldScale(Vec3 origin);

		Vec3 GetPosition() {
			return position;
		}

		float GetX() {
			return position.x;
		}
		
		float GetY() {
			return position.y;
		}

		float GetZ() {
			return position.z;
		}

		void SetPosition(float x, float y, float z) {
			position.x = x;
			position.y = y;
			position.z = z;

			UpdateWorldPosition();
		}

		void SetPosition(Vec3 position) {
			SetPosition(position.x, position.y, position.z);
		}
		
		Quaternion GetRotation() {
			return rotation;
		}

		void SetRotation(Quaternion rotation) {
			this->rotation = rotation;

			UpdateWorldRotation();
		}

		Vec3 GetScale() {
			return scale;
		}

		float GetScaleX() {
			return scale.x;
		}

		float GetScaleY() {
			return scale.y;
		}

		float GetScaleZ() {
			return scale.z;
		}

		void SetScale(float x, float y, float z) {
			scale.x = x;
			scale.y = y;
			scale.z = z;

			UpdateWorldScale(worldPosition);
		}

		void SetScale(Vec3 scale) {
			SetScale(scale.x, scale.y, scale.z);
		}
	};

}
