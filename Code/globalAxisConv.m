function [dTranslationX,dTranslationY] = globalAxisConv(carAngle,carVelocity,dopplerTX,dopplerTY)

rotMat = [cosd(carAngle) -sind(carAngle);
    sind(carAngle) cosd(carAngle)];

carVelX = carVelocity*cosd(carAngle);
carVelY = carVelocity*sind(carAngle);

carVelMat = [carVelX ; carVelY];

dTranslationX = zeros(length(dopplerTX),1);
dTranslationY = zeros(length(dopplerTY),1);

for i = 1:length(dopplerTX)
    
    Vdv = rotMat*[dopplerTX(i);dopplerTY(i)];
    
    Vdv = Vdv + carVelMat;
    
    dTranslationX(i) = Vdv(1);
    dTranslationY(i) = Vdv(2);

end