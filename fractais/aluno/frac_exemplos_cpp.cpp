 #include <lib/pen.h>

void bola(Pen& p, int raio){
    if(raio<0.001)
        return;
     p.circle(raio);

    for(int i = 0;i < 6; i++){
        p.right(60);
        p.up();
        p.walk(raio);
        p.down();
        bola(p, raio * 0.35);
        p.up();
        p.walk(-raio);
        p.down();



    }

}

void floco_neve(Pen& p, int lado){
    if(lado < 3)
        return;
    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco_neve(p, lado/ 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco_neve(p, lado/ 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco_neve(p, lado/ 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco_neve(p, lado/ 3);

    p.walk(lado);
    p.right(72);
    p.walk(-lado);
    floco_neve(p, lado/ 3);
}

void arvore(Pen& p, int lado){
    float ang = 35;
    float dec = 17;
    if(lado < 10)
        return;
    p.setColor(sf::Color::Green);
    p.walk(lado);
    p.right(ang);
    arvore(p, lado - dec);
    p.left(ang);
    arvore(p, lado - dec);
    p.left(ang);
    arvore(p,lado - dec);
    p.right(ang);

    p.walk(-lado);
}


void espiral_quadrado(Pen& p, int lado){
    if(lado < 5)
        return;

    for(int i = 0; i < 1; i++){
        p.walk(lado);
        p.right(90);

        p.walk(lado);
        p.right(90);

        p.walk(lado);
        p.right(90);

        p.walk(lado);

        p.up();

        p.walk(lado);

        p.rotate(60);
        p.down();
        espiral_quadrado(p, lado - 5);

    }

}


void triangulo(Pen &p,int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10)
    return;

    p.setColor(sf::Color::Green);
    p.walk(lado);
    p.right(ang);
    triangulo(p, lado * dec);
    p.left(ang);
    triangulo(p, lado * dec);
    p.left(ang);
    triangulo(p, lado * dec);
    p.right(ang);
    p.setColor(sf::Color::Red);
    p.walk(-lado);
}





void fractal(){
    int lado = 200;
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 410);

    //embuar(p,lado);
    //faz o pincel apontar pra direita
    p.setSpeed(25);
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade

    //p.circle(200);
    //linha(p, 100, -1);
    //espera clicar no botao de fechar

    //triangulo(p,lado);
    //espiral_quadrado(p,lado);
    //arvore(p,lado);
    //floco_neve(p,lado);
    bola(p,lado);
    p.wait();
}

int main(){
    fractal();
    return 0;
}
