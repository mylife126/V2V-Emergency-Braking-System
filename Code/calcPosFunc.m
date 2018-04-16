function [pedResultX,pedResultY,pedResultZ] = calcPosFunc(carX,carY,carZ,carRotZ,pedR,pedTheta,pedPhi,sensorCorrX,sensorCorrY,sensorCorrZ)

TcarMat = [1 0 0 carX ; 0 1 0 carY ; 0 0 1 carZ ; 0 0 0 1];
TsensorMat = [1 0 0 sensorCorrX ; 0 1 0 sensorCorrY ; 0 0 1 sensorCorrZ ; 0 0 0 1];
RcarMat = [cosd(carRotZ) -sind(carRotZ) 0 0 ;
        sind(carRotZ) cosd(carRotZ) 0 0;
        0 0 1 0;
        0 0 0 1];
    
pedResultX = zeros(length(pedR),1);
pedResultY = zeros(length(pedR),1);
pedResultZ = zeros(length(pedR),1);

for i = 1:length(pedR)
    
    [xPed,yPed,zPed] = sph2cart(-pedTheta(i)*pi/180,pedPhi*pi/180,pedR(i));
    
    TpedMat = [1 0 0 xPed ; 0 1 0 yPed ; 0 0 1 zPed ; 0 0 0 1];

    ResultMat = TcarMat*RcarMat*TsensorMat*TpedMat*[0;0;0;1];

    pedResultX(i) = ResultMat(1);
    pedResultY(i) = ResultMat(2);
    pedResultZ(i) = ResultMat(3);

end