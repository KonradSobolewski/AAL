function [ analysisVector ] = AnalysisOfAlgorithm(  )

disp('Make your prediction about algorithm running time. Type x -> O(n^x): ');
prompt = '...';
x = input(prompt);
fileID = fopen('dane.txt','r');
A=fscanf(fileID,'%f');

sizeVar=floor(size(A)/2);


for i=2:size(A)
    if mod(i,2)==0
        inputSize(i/2) = A(i);
    else 
        inputTime(floor((i+1)/2)) = A(i);
    end
end
inputTime(1) = A(1);
medianTime = median(inputTime);
medianSize = median(inputSize);

coefficient = medianSize^x / medianTime;


for i=1:sizeVar
    analysisVector(i) = inputTime(i) * coefficient / inputSize(i).^x;
end



end