function varargout = m3_9(varargin)
% M3_9 MATLAB code for m3_9.fig
%      M3_9, by itself, creates a new M3_9 or raises the existing
%      singleton*.
%
%      H = M3_9 returns the handle to a new M3_9 or the handle to
%      the existing singleton*.
%
%      M3_9('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in M3_9.M with the given input arguments.
%
%      M3_9('Property','Value',...) creates a new M3_9 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before m3_9_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to m3_9_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help m3_9

% Last Modified by GUIDE v2.5 06-May-2020 17:37:45

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @m3_9_OpeningFcn, ...
                   'gui_OutputFcn',  @m3_9_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before m3_9 is made visible.
function m3_9_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to m3_9 (see VARARGIN)

% Choose default command line output for m3_9
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes m3_9 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = m3_9_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
T = 10*(1/20);A =5;
Fs = 1000;
dt = 1/Fs;
t = 0:dt:T-dt;
x = A * sawtooth(2*pi*20*t);
plot(t,x)
grid on;