SetLocal EnableDelayedExpansion

cd Engine/Vendor/ImGUI
SET cFileNames=
FOR /R %%f in (*.cpp) do (
    SET cFileNames=!cFileNames! %%f
)
cd ..
cd ..
cd ..

g++ -g -shared %cFileNames% -IEngine/Vendor/ImGUI -IEngine/Vendor/GLFW/include -IEngine/Vendor/GLAD/include -LBin -lglfw3 -lglad -o Bin/ImGUI.dll