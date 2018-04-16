function [pedR,pedTheta,pedPhi] = calcSensorDataFunc(carX,carY,carZ,carRotZ,pedX,pedY,pedZ,sensorCorrX,sensorCorrY,sensorCorrZ)
%#codegen
TcarMat = [1 0 0 carX ; 0 1 0 carY ; 0 0 1 carZ ; 0 0 0 1];

RcarMat = [cosd(carRotZ) -sind(carRotZ) 0 0;
    sind(carRotZ) cosd(carRotZ) 0 0;
    0 0 1 0;
    0 0 0 1];

TsensorMat = [1 0 0 sensorCorrX ; 0 0 1 sensorCorrY ; 0 1 0 sensorCorrZ ; 0 0 0 1];

FcarMat = TcarMat*RcarMat*TsensorMat*[0;0;0;1];

pedR = zeros(length(pedX),1);
pedTheta = zeros(length(pedX),1);
pedPhi = zeros(length(pedX),1);

for i = 1:length(pedX)

[pedThetaTemp,pedPhiTemp,pedRTemp] = cart2sph(pedX(i) - FcarMat(1), pedY(i) - FcarMat(2), pedZ - FcarMat(3));

pedR(i) = pedRTemp;
pedTheta(i) = -(pedThetaTemp*180/pi-carRotZ);
pedPhi(i) = pedPhiTemp*180/pi;

end