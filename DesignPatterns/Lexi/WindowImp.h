
#include <wx/wxprec.h>
#include<iostream>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Panel: public wxPanel{
    private:
        double sx; 
        double sy;
    public:
        Panel(wxFrame *frame): wxPanel(frame, wxID_ANY){
            sx = 1.0;
            sy = 1.0;
        }
        ~Panel(){}
        void SetScale(double sx = 1.0, double sy = 1.0){
            this->sx = sx;
            this->sy = sy;
        }
        void DrawLine(const wxPoint& p0, const wxPoint& p1){
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawRectangle(wxRect(p0, p1));
        }
        void DrawRectangle(const wxPoint& p0, const wxPoint& p1){
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawRectangle(wxRect(p0, p1));
        }
        void DrawPolygon(const int &n ,const wxPoint p []){
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.DrawPolygon(n, p);
        }
        void DrawText(const char &c, const wxPoint& p, const wxFont &font){
            wxClientDC dc(this);
            wxPen pen(wxColour(0, 0, 0, 0));
            dc.SetPen(pen);
            dc.SetFont(font);
            dc.DrawText(wxString(c), p);
        }
};

class WindowImp{
    public:
        virtual void DrawLine(const wxPoint&, const wxPoint&) = 0;
        virtual void DeviceRect(const wxPoint& , const wxPoint&) = 0;
        virtual void DrawPolygon(const int&, const wxPoint []) = 0;
        virtual void DeviceText(const char&, const wxPoint&, const wxFont&) = 0;
};

class WindowsWindowImp : public WindowImp, public wxFrame{  
    private:
        Panel *panel;
    public:
        WindowsWindowImp(const wxString &title = ""):wxFrame(NULL, wxID_ANY, title) {
            panel = new Panel(this);
            Center();
        }
        ~WindowsWindowImp(){}
        void DrawLine(const wxPoint& p0, const wxPoint& p1){
            panel->DrawLine(p0, p1);
        }
        void DeviceRect(const wxPoint& p0, const wxPoint& p1){
            panel->DrawRectangle(p0, p1);
        }
        void DrawPolygon(const int &n, const wxPoint p []){
            panel->DrawPolygon(n, p);
        }
        void DeviceText(const char &c, const wxPoint& p0, const wxFont &font){
            panel->DrawText(c, p0, font);
        }
        int OnExit(wxCommandEvent& event){
            Close(true);
            return 0;
        }
};