function [pedR_Array,pedTheta_Array,dVel_Array] = adaptDataFunc(pedR_self,pedTheta_self,dVel_self,pedR_rcvd,pedTheta_rcvd,dVel_rcvd)

pedR_Array = zeros(32,1);
pedTheta_Array = zeros(32,1);
dVel_Array = zeros(32,1);

for i=1:length(pedR_self)
    pedR_Array(i) = pedR_self(i);
    pedTheta_Array(i) = pedTheta_self(i);
    dVel_Array(i) = dVel_self(i);
end

for i=1:length(pedR_rcvd)
    pedR_Array(i + length(pedR_self)) = pedR_rcvd(i);
    pedTheta_Array(i + length(pedR_self)) = pedTheta_rcvd(i);
    dVel_Array(i + length(pedR_self)) = dVel_rcvd(i);
end