#ifndef _G15STANDARDLAYOUT_HPP_
#define _G15STANDARDLAYOUT_HPP_

#include "G15Widget.hpp"
#include "CanvasManager.hpp"
#include "Renderable.hpp"

class G15StandardLayout : public Renderable {
	public:
		G15StandardLayout(CanvasManager *cm, const char* title = 0, G15Widget* main = NULL);
		G15StandardLayout(VirtualCanvas *vc, const char* title = 0, G15Widget* main = NULL);
		~G15StandardLayout();
		void setMainWidget(G15Widget *widget);
		G15Widget* getMainWidget();
		virtual int render();
	protected:
		void init(const char* title, G15Widget* main);
	private:
		G15Widget *titlebar;
		G15Widget *buttonBar;
		G15Widget *mainWidget;
		G15Widget *canvas;
};



#endif

