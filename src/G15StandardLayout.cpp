#include "G15StandardLayout.hpp"
#include "G15TitleBar.hpp"

G15StandardLayout::G15StandardLayout(CanvasManager *cm, const char* title, G15Widget* main){
	canvas = new G15Widget(cm);
	init(title,main);
}

G15StandardLayout::G15StandardLayout(VirtualCanvas *vc, const char* title, G15Widget* main){
	canvas = new G15Widget(vc);
	init(title,main);
}

G15StandardLayout::~G15StandardLayout(){
	delete canvas;
	delete titlebar;
}

void G15StandardLayout::setMainWidget(G15Widget *widget){
	if(mainWidget != NULL){
		canvas->deleteWidget(mainWidget);
	}
	mainWidget = widget;
	canvas->addWidget(mainWidget,0);
	canvas->deleteWidget(titlebar);
	canvas->addWidget(titlebar,0);
}

G15Widget* G15StandardLayout::getMainWidget(){
	return mainWidget;
}

int G15StandardLayout::render(){
	return canvas->render();
}

void G15StandardLayout::init(const char* title, G15Widget* main){
	mainWidget = main;
	titlebar = new G15TitleBar("",canvas);
	if(title){
		((G15TitleBar*)titlebar)->setText(title);
	}
	
	if(main != NULL){
		canvas->addWidget(main,0);
	}
	
	canvas->addWidget(titlebar,0);
}
	