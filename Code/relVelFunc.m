function dopplerVelocity = relVelFunc(carX,carY,carZ,carAngle,carVelocity,pedX,pedY,pedZ,dTranslationX,dTranslationY,dTranslationZ,sensorX,sensorY,sensorZ)

rotMat = [cosd(carAngle) -sind(carAngle);
    sind(carAngle) cosd(carAngle)];

sensorMat = rotMat*[sensorX ; sensorY];

carVelX = carVelocity*cosd(carAngle);
carVelY = carVelocity*sind(carAngle);

carVelMat = rotMat\[carVelX ; carVelY];

carMat = [carX + sensorMat(1) ; carY + sensorMat(2)];

dopplerVelocity = zeros(length(pedX),1);

for i = 1:length(pedX)
   
    Vcp = [pedX(i) - carMat(1) ; pedY(i) - carMat(2)];

    Vdv = rotMat\[dTranslationX(i) ; dTranslationY(i)];
    
    Vdv = Vdv - carVelMat;
    
    Vcp = rotMat\Vcp;
    
    dopplerVelocity(i) = dot(Vdv,Vcp)/norm(Vcp);
    
end
