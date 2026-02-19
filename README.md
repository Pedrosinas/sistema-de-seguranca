# sistema-de-seguranca
Projeto Final do IFF Campus Campos Centro

para compilar:
g++ main.cpp \
    src/db/Database.cpp \
    src/models/Aluno.cpp \
    src/models/Administrador.cpp \
    src/ui/LoginDialog.cpp \
    src/ui/CadastroAlunoFrame.cpp \
    `wx-config --cxxflags --libs` -lmariadb -o sistema
