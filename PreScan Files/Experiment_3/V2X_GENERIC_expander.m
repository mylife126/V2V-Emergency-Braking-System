function [u] = V2X_GENERIC_expander(y, z)
%#eml
  u = z;
  u = FILTER_PRESCAN_V2X_FIXED_GENERIC_MESSAGE(u, y);
end

function [u] = FILTER_PRESCAN_V2X_FIXED_GENERIC_MESSAGE(u, y)
  u.HEADER = FILTER_PRESCAN_HEADER(u.HEADER, y.HEADER);
  u.DATA = FILTER_PRESCAN_V2X_FIXED_GENERIC_DATA(u.DATA, y.DATA);
end

function [u] = FILTER_PRESCAN_HEADER(u, y)
  u.valid = y.valid;
end

function [u] = FILTER_PRESCAN_V2X_FIXED_GENERIC_DATA(u, y)
  u.messageID = y.messageID;
  u.senderID = y.senderID;
  u.signal_1 = y.signal_1;
  u.signal_2 = y.signal_2;
  u.signal_3 = y.signal_3;
  u.signal_4 = y.signal_4;
  u.signal_5 = y.signal_5;
  u.signal_6 = y.signal_6;
  u.signal_7 = y.signal_7;
  u.signal_8 = y.signal_8;
  u.signal_9 = y.signal_9;
  u.signal_10 = y.signal_10;
  u.discrete_signal_1 = y.discrete_signal_1;
  u.discrete_signal_2 = y.discrete_signal_2;
  u.discrete_signal_3 = y.discrete_signal_3;
  u.discrete_signal_4 = y.discrete_signal_4;
  u.discrete_signal_5 = y.discrete_signal_5;
  u.discrete_signal_6 = y.discrete_signal_6;
  u.discrete_signal_7 = y.discrete_signal_7;
  u.discrete_signal_8 = y.discrete_signal_8;
  u.discrete_signal_9 = y.discrete_signal_9;
  u.discrete_signal_10 = y.discrete_signal_10;
end

