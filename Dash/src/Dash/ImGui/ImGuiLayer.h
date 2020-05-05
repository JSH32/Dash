#pragma once

#include "Dash/Core/Layer.h"

#include "Dash/Events/ApplicationEvent.h"
#include "Dash/Events/MouseEvent.h"
#include "Dash/Events/KeyEvent.h"

namespace Dash
{
	class DASH_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
