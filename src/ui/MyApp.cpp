//
// Created by stanislav on 26. 1. 19..
//

#include "MyApp.h"
#include "MyFrame.h"

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame(_T("Hello World"));
    frame->Show(true);
    return true;
}
