function msfcn_PPS_PlotSpeed(block)
setup(block);
%endfunction

function setup( block )


%% define number of input and output ports
block.NumInputPorts  = 8;
block.NumOutputPorts = 0;


%% port properties
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

block.InputPort(1).Complexity = 'real'; % Vehicle velocity
block.InputPort(1).DataTypeId = 0; %real
block.InputPort(1).SamplingMode = 'Sample';
block.InputPort(1).Dimensions = 1;

block.InputPort(2).Complexity = 'real'; % RPM
block.InputPort(2).DataTypeId = 0; %real
block.InputPort(2).SamplingMode = 'Sample';
block.InputPort(2).Dimensions = 1;

block.InputPort(3).Complexity = 'real'; % Brake
block.InputPort(3).DataTypeId = 0; %real
block.InputPort(3).SamplingMode = 'Sample';
block.InputPort(3).Dimensions = 1; 

block.InputPort(4).Complexity = 'real'; % Detection flag
block.InputPort(4).DataTypeId = -1; %logical
block.InputPort(4).SamplingMode = 'Sample';
block.InputPort(4).Dimensions = 1; 

block.InputPort(5).Complexity = 'real'; % Warning flag
block.InputPort(5).DataTypeId = -1; %logical
block.InputPort(5).SamplingMode = 'Sample';
block.InputPort(5).Dimensions = 1;

block.InputPort(6).Complexity = 'real'; % Braking flag
block.InputPort(6).DataTypeId = -1; %logical
block.InputPort(6).SamplingMode = 'Sample';
block.InputPort(6).Dimensions = 1;

block.InputPort(7).Complexity = 'real'; % Pedestrian flag
block.InputPort(7).DataTypeId = -1; %logical
block.InputPort(7).SamplingMode = 'Sample';
block.InputPort(7).Dimensions = 1;

block.InputPort(8).Complexity = 'real'; % TTC
block.InputPort(8).DataTypeId = 0; %real
block.InputPort(8).SamplingMode = 'Sample';
block.InputPort(8).Dimensions = 1;

%% Register parameters
block.NumDialogPrms     = 2;
dfreq = block.DialogPrm(1).Data;

%% block sample time
block.SampleTimes = [1/dfreq 0];

%% register methods
block.RegBlockMethod('Start', @Start);
block.RegBlockMethod('Outputs', @Outputs);

%% Block runs on TLC in accelerator mode.
block.SetAccelRunOnTLC(true);
%endfunction

function Start(block)

if block.DialogPrm(2).Data;
    
    try%#ok<TRYNC>
        close(PPS_PlotSpeed);
    end
    
    h_dlg   = PPS_PlotSpeed;
    
    h_speed = findobj(h_dlg, 'Tag', 'Speed_text');
    h_brake = findobj(h_dlg, 'Tag', 'BrakePressure_text');
    h_RPM   = findobj(h_dlg, 'Tag', 'RPM_text');
    h_coll_value = findobj(h_dlg, 'Tag', 'collision_value');
    h_ped_value  = findobj(h_dlg, 'Tag', 'ped_value');
    h_warn_value = findobj(h_dlg, 'Tag', 'warn_value');
    h_brake_value = findobj(h_dlg, 'Tag', 'brake_value');
    h_cs_value = findobj(h_dlg, 'Tag', 'cs_value');
    
    h_coll_text1 = findobj(h_dlg, 'Tag', 'collision_text1');
    h_coll_text2 = findobj(h_dlg, 'Tag', 'collision_text2');
    h_ped_text1 = findobj(h_dlg, 'Tag', 'ped_text1');
    h_ped_text2 = findobj(h_dlg, 'Tag', 'ped_text2');
    h_warn_text1 = findobj(h_dlg, 'Tag', 'warn_text1');
    h_warn_text2 = findobj(h_dlg, 'Tag', 'warn_text2');
    h_brake_text1 = findobj(h_dlg, 'Tag', 'brake_text1');
    h_brake_text2 = findobj(h_dlg, 'Tag', 'brake_text2');
    
    h_coll_panel = findobj(h_dlg, 'Tag', 'collision_panel');
    h_ped_panel = findobj(h_dlg, 'Tag', 'ped_panel');
    h_warn_panel = findobj(h_dlg, 'Tag', 'warn_panel');
    h_brake_panel = findobj(h_dlg, 'Tag', 'brake_panel');
    h_cs_panel = findobj(h_dlg, 'Tag', 'cs_panel');
    
    
    handles = [h_dlg h_speed h_brake h_RPM h_coll_value h_ped_value ...
        h_warn_value h_brake_value h_cs_value h_coll_text1 h_coll_text2 h_ped_text1 ...
        h_ped_text2 h_warn_text1 h_warn_text2 h_brake_text1 h_brake_text2 h_coll_panel ...
        h_ped_panel h_warn_panel h_brake_panel h_cs_panel];
    set_param(block.BlockHandle,'UserData',handles);
end
%endfunction Start

function Outputs(block)

    handles = get_param(block.BlockHandle,'UserData');

    % Velocity and RPM
    h_speed = handles(2);
    h_brake = handles(3);
    h_RPM = handles(4);
    set(h_speed, 'String', num2str(round(block.InputPort(1).Data)));
    set(h_RPM,   'String', num2str(block.InputPort(2).Data) );
    set(h_brake, 'String', num2str(block.InputPort(3).Data) );
    
    % Get TTC value
    ttcn = block.InputPort(8).Data;
    ttcs = sprintf('%.2f',ttcn);
    
    % Get a value of braking flag
    brake_flag = block.InputPort(6).Data;
    
    % Detection flag
    h_coll_value = handles(5);
    h_coll_text1 = handles(10);
    h_coll_text2 = handles(11);
    h_coll_panel = handles(18);
    if block.InputPort(4).Data
       set(h_coll_panel, 'BorderWidth',2, 'ForegroundColor','Black', 'HighlightColor',[0.502 0.502 0.502], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_coll_value, 'ForegroundColor', 'Black');
       set(h_coll_text1, 'ForegroundColor', 'Black');
       set(h_coll_text2, 'ForegroundColor', 'Black');
       set(h_coll_value, 'ForegroundColor', 'Black');
       if strcmp( get(h_coll_value, 'String'), '_.__')
           set(h_coll_value, 'String', ttcs);
       end
    else
       set(h_coll_panel, 'BorderWidth',1, 'ForegroundColor',[0.9,0.9,0.9], 'HighlightColor',[0.5 0.5 0.5], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_coll_value, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_coll_text1, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_coll_text2, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_coll_value, 'ForegroundColor', [0.9 0.9 0.9]);
       if (~strcmp( get(h_coll_value, 'String'), '_.__')) 
           set(h_coll_value, 'String', '_.__');
       end
    end
    
    % Pedestrian flag
    h_ped_value = handles(6);
    h_ped_text1 = handles(12);
    h_ped_text2 = handles(13);
    h_ped_panel = handles(19);
    if block.InputPort(7).Data
       set(h_ped_panel, 'BorderWidth',2, 'ForegroundColor','Black', 'HighlightColor',[0.502 0.502 0.502], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_ped_value, 'ForegroundColor', 'Black');
       set(h_ped_text1, 'ForegroundColor', 'Black');
       set(h_ped_text2, 'ForegroundColor', 'Black');
       set(h_ped_value, 'ForegroundColor', 'Black');
       if strcmp( get(h_ped_value, 'String'), '_.__')
           set(h_ped_value, 'String', ttcs);
       end
    else
       set(h_ped_panel, 'BorderWidth',1, 'ForegroundColor',[0.9,0.9,0.9], 'HighlightColor',[0.5 0.5 0.5], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_ped_value, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_ped_text1, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_ped_text2, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_ped_value, 'ForegroundColor', [0.9 0.9 0.9]);
       if ~strcmp( get(h_ped_value, 'String'), '_.__')
           set(h_ped_value, 'String', '_.__');
       end
    end
    
    % Warning flag  
    h_warn_value = handles(7);
    h_warn_text1 = handles(14);
    h_warn_text2 = handles(15);
    h_warn_panel = handles(20);
    if block.InputPort(5).Data
       set(h_warn_panel, 'BorderWidth',2, 'ForegroundColor',[1 0.6471 0], 'HighlightColor',[1 0.6471 0], 'ShadowColor', [1 0.6471 0]);
       set(h_warn_value, 'ForegroundColor', [1 0.6471 0]);
       set(h_warn_text1, 'ForegroundColor', [1 0.6471 0]);
       set(h_warn_text2, 'ForegroundColor', [1 0.6471 0]);
       set(h_warn_value, 'ForegroundColor', [1 0.6471 0]);
       if strcmp( get(h_warn_value, 'String'), '_.__')
           set(h_warn_value, 'String', ttcs);
       end
    else
       set(h_warn_panel, 'BorderWidth',1, 'ForegroundColor',[0.9,0.9,0.9], 'HighlightColor',[0.5 0.5 0.5], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_warn_value, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_warn_text1, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_warn_text2, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_warn_value, 'ForegroundColor', [0.9 0.9 0.9]);
       if ~strcmp( get(h_warn_value, 'String'), '_.__')
           set(h_warn_value, 'String', '_.__');
       end
    end
    
    % Braking flag
    h_brake_value = handles(8);
    h_brake_text1 = handles(16);
    h_brake_text2 = handles(17);
    h_brake_panel = handles(21);
    if brake_flag
       set(h_brake_panel, 'BorderWidth',2, 'ForegroundColor','Red', 'HighlightColor','Red', 'ShadowColor', 'Red');
       set(h_brake_value, 'ForegroundColor', 'Red');
       set(h_brake_text1, 'ForegroundColor', 'Red');
       set(h_brake_text2, 'ForegroundColor', 'Red');
       set(h_brake_value, 'ForegroundColor', 'Red');
       if strcmp( get(h_brake_value, 'String'), '_.__')
           set(h_brake_value, 'String', ttcs);
       end
    else
       set(h_brake_panel, 'BorderWidth',1, 'ForegroundColor',[0.9,0.9,0.9], 'HighlightColor',[0.5 0.5 0.5], 'ShadowColor', [0.5 0.5 0.5]);
       set(h_brake_value, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_brake_text1, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_brake_text2, 'ForegroundColor', [0.9 0.9 0.9]);
       set(h_brake_value, 'ForegroundColor', [0.9 0.9 0.9]);
       if ~strcmp( get(h_brake_value, 'String'), '_.__')
           set(h_brake_value, 'String', '_.__');
       end
    end
%endfunction Outputs
