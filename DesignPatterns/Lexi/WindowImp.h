
#ifndef WINDOWIMPDEF
#define WINDOWIMPDEF

//#include "ActionObserver.h"

class Panel: public wxPanel{
    private:
        wxBitmap *bt;
        wxClientDC *display;
        wxMemoryDC *dc; 
        double sx; 
        double sy;
    public:
        Panel(wxFrame *frame): wxPanel(frame, wxID_ANY){
            display = new wxClientDC(this); 
            bt = new wxBitmap(frame->GetSize());
            dc = new wxMemoryDC(*bt);
            dc->SetBackground(*wxWHITE_BRUSH);
            dc->Clear(); 
            sx = 1.0;
            sy = 1.0;
            Bind(wxEVT_MOTION, &Motion, this);

            Bind(wxEVT_LEFT_DOWN, &LeftClickDown, this);
            Bind(wxEVT_MIDDLE_DOWN, &MiddleClickDown, this);
            Bind(wxEVT_RIGHT_DOWN, &RightClickDown, this);
            
            Bind(wxEVT_LEFT_UP, &LeftClickUp, this);
            Bind(wxEVT_MIDDLE_UP, &MiddleClickUp, this);
            Bind(wxEVT_RIGHT_UP, &RightClickUp, this);
            
            Bind(wxEVT_LEFT_DCLICK, &LeftDClick, this);
            Bind(wxEVT_MIDDLE_DCLICK, &MiddleDClick, this);
            Bind(wxEVT_RIGHT_DCLICK, &RightDClick, this);
        
            Bind(wxEVT_MOUSEWHEEL, &MouseWheel, this);
        }
        ~Panel(){}
        
        /*
            EVT_LEFT_DOWN(func):
            Process a wxEVT_LEFT_DOWN event. The handler of this event should normally call event.Skip() to allow the default processing to take place as otherwise the window under mouse wouldn't get the focus.
            EVT_LEFT_UP(func):
            Process a wxEVT_LEFT_UP event.
            EVT_LEFT_DCLICK(func):
            Process a wxEVT_LEFT_DCLICK event.
            EVT_MIDDLE_DOWN(func):
            Process a wxEVT_MIDDLE_DOWN event.
            EVT_MIDDLE_UP(func):
            Process a wxEVT_MIDDLE_UP event.
            EVT_MIDDLE_DCLICK(func):
            Process a wxEVT_MIDDLE_DCLICK event.
            EVT_RIGHT_DOWN(func):
            Process a wxEVT_RIGHT_DOWN event.
            EVT_RIGHT_UP(func):
            Process a wxEVT_RIGHT_UP event.
            EVT_RIGHT_DCLICK(func):
            Process a wxEVT_RIGHT_DCLICK event.
            EVT_MOUSE_AUX1_DOWN(func):
            Process a wxEVT_AUX1_DOWN event.
            EVT_MOUSE_AUX1_UP(func):
            Process a wxEVT_AUX1_UP event.
            EVT_MOUSE_AUX1_DCLICK(func):
            Process a wxEVT_AUX1_DCLICK event.
            EVT_MOUSE_AUX2_DOWN(func):
            Process a wxEVT_AUX2_DOWN event.
            EVT_MOUSE_AUX2_UP(func):
            Process a wxEVT_AUX2_UP event.
            EVT_MOUSE_AUX2_DCLICK(func):
            Process a wxEVT_AUX2_DCLICK event.
            EVT_MOTION(func):
            Process a wxEVT_MOTION event.
            EVT_ENTER_WINDOW(func):
            Process a wxEVT_ENTER_WINDOW event.
            EVT_LEAVE_WINDOW(func):
            Process a wxEVT_LEAVE_WINDOW event.
            EVT_MOUSEWHEEL(func):
            Process a wxEVT_MOUSEWHEEL event.
            EVT_MOUSE_EVENTS(func):
            Process all mouse events.
        */
        //events
        void SetScale(double sx = 1.0, double sy = 1.0){
            this->sx = sx;
            this->sy = sy;
        }
        void Motion(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        //ClickDown
        void LeftClickDown(wxMouseEvent &event){
            wxPostEvent(GetParent(), event);
        }
        void MiddleClickDown(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        void RightClickDown(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        //ClickUp
        void LeftClickUp(wxMouseEvent &event){
            wxPostEvent(GetParent(), event);
        }
        void MiddleClickUp(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        void RightClickUp(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        //doubleClicks
        void LeftDClick(wxMouseEvent &event){
            wxPostEvent(GetParent(), event);
        }
        void MiddleDClick(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        void RightDClick(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        //MouseWheel
        void MouseWheel(wxMouseEvent& event){
            wxPostEvent(GetParent(), event);
        }
        void render(){
            display->DrawBitmap(*bt, wxPoint(0,0));
        }
        void DrawLine(const wxPoint& p0, const wxPoint& p1){
            /*wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawLine(p0, p1);*/
            dc->SelectObject(*bt);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc->SetPen(pen);
            dc->DrawLine(p0, p1);
            /*
            xImage img = wxImage();
            img.AddHandler(new wxPNGHandler);
            img.LoadFile("J:/blender/HushPuppy/Scene1_frames/0000.png", wxBITMAP_TYPE_PNG);
            bt = new wxBitmap(img);
            */
            bt->Rescale(*bt, dc->GetSize());
            dc->SelectObject(wxNullBitmap);
        }
        void DrawRectangle(const wxPoint& p0, const wxPoint& p1){
            /*
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawRectangle(wxRect(p0, p1));
            */
        }
        void DrawPolygon(const int &n ,const wxPoint p []){
            /*
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawPolygon(n, p);
            */
        }
        void DrawText(const char &c, const wxPoint& p, const wxFont &font){
            /*
            wxMemoryDC dc(*bt);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.SetFont(font);
            */
            dc->SelectObject(*bt);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc->SetPen(pen);
            dc->SetFont(font);
            dc->DrawText(wxString(c), p);
            /*
            xImage img = wxImage();
            img.AddHandler(new wxPNGHandler);
            img.LoadFile("J:/blender/HushPuppy/Scene1_frames/0000.png", wxBITMAP_TYPE_PNG);
            bt = new wxBitmap(img);
            */
            bt->Rescale(*bt, dc->GetSize());
            dc->SelectObject(wxNullBitmap);
        }
        wxSize getCharSize(const char &c, const wxFont &font){
            dc->SetFont(font);
            wxSize size = wxSize();
            dc->GetTextExtent(wxString(c), &size.x, &size.y);
            return size;
        }
};

class WindowImp{
    public:
        virtual void DeviceLine(const wxPoint&, const wxPoint&) = 0;
        virtual void DeviceRect(const wxPoint& , const wxPoint&) = 0;
        virtual void DevicePolygon(const int&, const wxPoint []) = 0;
        virtual void DeviceText(const char&, const wxPoint&, const wxFont&) = 0;
        //Observer features
        /*
        virtual void Attach(Observer*){};
        virtual void Detach(Observer*){};
        virtual void Notify(){};
        */
};
class ActionEvent: public wxMouseEvent, public wxKeyEvent{
    private:
        bool Consumed, MouseEvent, KeyEvent;
    public:
        ActionEvent():wxMouseEvent(wxEVT_NULL),wxKeyEvent(wxEVT_NULL){
            Consumed = false;
            MouseEvent = false;
            KeyEvent = false;
        };
        ActionEvent(wxKeyEvent& event):wxMouseEvent(wxEVT_NULL),wxKeyEvent(event){
            Consumed = false;
            MouseEvent = false;
            KeyEvent = false;
        };
        ActionEvent(wxMouseEvent& event):wxMouseEvent(event),wxKeyEvent(wxEVT_NULL){
            Consumed = false;
            MouseEvent = false;
            KeyEvent = false;
        };
        void MouseEventEnded(){
            MouseEvent = false;
        }
        void KeyEventEnded(){
            KeyEvent = false;
        }
        void SetEvent(wxMouseEvent& me){
            if(!MouseEvent){
                (*this) = me;
                MouseEvent = true;
                KeyEvent = false;
            }
            else
                me.Skip();
        }
        void SetEvent(wxKeyEvent& ke){
            if(!KeyEvent){
                (*this) = ke;
                MouseEvent = false;
                KeyEvent = true;
            }
            else
                ke.Skip();
        }
        bool isKeyEvent(){
            return KeyEvent;
        }
        bool isMouseEvent(){
            return MouseEvent;
        }
};

class WindowsWindowImp : public WindowImp, public wxFrame{  
    private:
        bool shown, Quit, KeyEvent, MouseEvent;
        Panel *panel;
        long int CharCount;
        ActionEvent actionEvent;
        wxKeyEvent ke;
        wxMouseEvent me;
    public:
        WindowsWindowImp(const wxString &title = "", const wxSize &size = wxSize(wxDefaultSize)):
            wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size) {
                panel = new Panel(this);
                shown = false;
                CharCount = 0;
                Quit = false;
                Center();
                BindEvents();
                SetFocus();
                ke = wxKeyEvent();
                me = wxMouseEvent();
                KeyEvent = false;
                MouseEvent = false;
        }
        ~WindowsWindowImp(){
            delete panel;
        }
        //ObserverFunctions
        /*
        void Attach(Observer* o){
            ao = o;
        }
        void Detach(Observer* o){
            ao = NULL;
        }
        */
        //States
        void BlockEvents(){
            Unbind(wxEVT_CHAR, &SetKeyEvent, this);
            Unbind(wxEVT_KEY_UP, &KeyUp, this);
            Unbind(wxEVT_KEY_DOWN, &KeyDown, this);

            Unbind(wxEVT_MOTION, &SetMouseEvent, this);

            Unbind(wxEVT_LEFT_DOWN, &SetMouseEvent, this);
            Unbind(wxEVT_MIDDLE_DOWN, &SetMouseEvent, this);
            Unbind(wxEVT_RIGHT_DOWN, &SetMouseEvent, this);
            
            Unbind(wxEVT_LEFT_UP, &SetMouseEvent, this);
            Unbind(wxEVT_MIDDLE_UP, &SetMouseEvent, this);
            Unbind(wxEVT_RIGHT_UP, &SetMouseEvent, this);
            
            Unbind(wxEVT_LEFT_DCLICK, &SetMouseEvent, this);
            Unbind(wxEVT_MIDDLE_DCLICK, &SetMouseEvent, this);
            Unbind(wxEVT_RIGHT_DCLICK, &SetMouseEvent, this);

            Unbind(wxEVT_MOUSEWHEEL, &SetMouseEvent, this);

            Unbind(wxEVT_CLOSE_WINDOW, &CloseWindow, this);
        }
        void BindEvents(){
                Bind(wxEVT_CHAR, &SetKeyEvent, this);
                Bind(wxEVT_KEY_UP, &KeyUp, this);
                //Bind(wxEVT_KEY_DOWN, &KeyDown, this);

                Bind(wxEVT_MOTION, &SetMouseEvent, this);

                Bind(wxEVT_LEFT_DOWN, &SetMouseEvent, this);
                Bind(wxEVT_MIDDLE_DOWN, &SetMouseEvent, this);
                Bind(wxEVT_RIGHT_DOWN, &SetMouseEvent, this);
                
                Bind(wxEVT_LEFT_UP, &SetMouseEvent, this);
                Bind(wxEVT_MIDDLE_UP, &SetMouseEvent, this);
                Bind(wxEVT_RIGHT_UP, &SetMouseEvent, this);
                
                Bind(wxEVT_LEFT_DCLICK, &SetMouseEvent, this);
                Bind(wxEVT_MIDDLE_DCLICK, &SetMouseEvent, this);
                Bind(wxEVT_RIGHT_DCLICK, &SetMouseEvent, this);

                Bind(wxEVT_MOUSEWHEEL, &SetMouseEvent, this);

                Bind(wxEVT_CLOSE_WINDOW, &CloseWindow, this);
        }
        ActionEvent GetActionEvent(){
            return this->actionEvent;
        }
        void SetKeyEvent(wxKeyEvent& event){
            //std::cout<< char(event.GetUnicodeKey()) << std::endl;
            ke = event;
            KeyEvent = true;
            MouseEvent = false;
        }
        void KeyUp(wxKeyEvent& event){
            KeyEvent = false;
            MouseEvent = true;
        }
        void KeyDown(wxKeyEvent& event){}
        void SetMouseEvent(wxMouseEvent& event){
            me = event;
        }
        wxKeyEvent& getKeyEvent(){
            return ke;
        }
        bool isKeyEvent(){
            return KeyEvent;
        }
        wxMouseEvent& getMouseEvent(){
            return me;
        }
        void Notify(){
        /*
            if(ao == NULL)  
                ao = new ActionObserver();
            ao->Update(GetCurrentEvent());
        */
        }
        //events
        void ReDraw(){
            panel->render();
        }
        void render(){
            panel->render();
        }
        bool IsQuited(){
            return Quit;
        }
        void CloseWindow(wxCloseEvent& event){
            Quit = true;
            event.Skip();
        }
        void Maximize(wxMaximizeEvent& event){
            
        }
        void Iconify(wxIconizeEvent& event){
            if(shown){
                shown = false;
            }
            else{
                Deiconify();
            }
        }
        void Deiconify(){
            //code here
            shown = Show(true);
            panel->render();
        }
        //functions
        bool Show(bool s = true){
            shown = wxTopLevelWindowMSW::Show(s);
            wxSize size = GetSize();
            size = GetSize();
            //if(s)
                //Refresh();
            //wxWindow::SetMaxSize(ClientToWindowSize(size));
            return shown;
        }
        bool IsShown(){
            return shown;
        }
        void DeviceLine(const wxPoint& p0, const wxPoint& p1){
            panel->DrawLine(p0, p1);
        }
        void DeviceRect(const wxPoint& p0, const wxPoint& p1){
            panel->DrawRectangle(p0, p1);
        }
        void DevicePolygon(const int &n, const wxPoint p []){
            panel->DrawPolygon(n, p);
        }
        void DeviceText(const char &c, const wxPoint& p0, const wxFont &font){
            panel->DrawText(c, p0, font);
        }
        wxSize getCharSize(const char &c, const wxFont &font){
            return panel->getCharSize(c, font);
        }
};

#endif