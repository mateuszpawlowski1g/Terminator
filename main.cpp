#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.h"
#include "button.h"
#include "health.h"
#include "Hero.h"
#include "map.h"
#include "meleeenemy.h"
#include "rangeenemy.h"
#include "terminator.h"
#include "wall.h"
#include"bullet.h"
#include <vector>
int main()
{

    sf::RenderWindow window(sf::VideoMode(1600, 800), "Terminator");
    std::cout<<"-------------"<<std::endl;
    std::vector<bullet> obiekty;
    std::vector<bullet> obiekty2;
    std::vector<bullet> strzaly_gracza;
    std::vector<bullet> strzaly_gracza2;
    std::vector<MeleeEnemy> mele_wrogowie;
    std::vector<int>mele_rozm={800,400,810,410,0,0,10,10,0,800,10,800,1590,10,1590,0,400,0,400,10};
    std::vector<sf::Texture> textury_mele;
    std::vector<MeleeEnemy> mele_wrogowie2;
    std::vector<int>mele_rozm2={300,0,300,10,300,20,400,0,400,10,400,20,500,0,500,10,500,20,600,0,600,10,600,20,
                                300,770,300,790,300,780,400,770,400,790,400,780,500,770,500,790,500,780,
                                600,770,600,790,600,780,10,300,20,300,30,300,10,500,20,500,30,500};
    std::vector<sf::Texture> textury_mele2;
    std::vector<RangeEnemy> ran_wrogowie;
    std::vector<int>ran_rozm={800,400,810,410,0,0,10,10,0,800,10,800,1590,10,1590,0,400,0,400,10};
    std::vector<sf::Texture> textury_ran;
    std::vector<RangeEnemy> ran_wrogowie2;
    std::vector<int>ran_rozm2={300,0,300,10,300,20,400,0,400,10,400,20,500,0,500,10,500,20,600,0,600,10,600,20,
                               300,770,300,790,300,780,400,770,400,790,400,780,500,770,500,790,500,780,
                               600,770,600,790,600,780,10,300,20,300,30,300,10,500,20,500,30,500};
    std::vector<sf::Texture> textury_ran2;
    std::vector<sf::RectangleShape>walls;
    std::vector<sf::RectangleShape>walls2;
    std::vector<int>walls_rozm2={200,200,900,200,1100,200,1300,200};
    std::vector<int>walls_rozm={0,400,400,200,400,600,1000,0,1400,200,800,600,1000,600};
    int level =0;
    int pomocniczy=0;
    for(int j=0;j<10;j++){
        sf::Texture tekstura;
        textury_mele.emplace_back(tekstura);
    }
    for(int j=0;j<30;j++){
        sf::Texture tekstura;
        textury_mele2.emplace_back(tekstura);
    }
    for(int j=0;j<10;j++){
        sf::Texture tekstura;
        textury_ran.emplace_back(tekstura);
    }
    for(int j=0;j<30;j++){
        sf::Texture tekstura;
        textury_ran2.emplace_back(tekstura);
    }
    for(int i=0;i<10;i++){

        MeleeEnemy mel(textury_mele[i]);

        if (!textury_mele[i].loadFromFile("tekstury/mele.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
        mel.setTexture(textury_mele[i]);

        mel.setPosition(mele_rozm[2*i],mele_rozm[2*i+1]);

        mele_wrogowie.emplace_back(mel);

    }
    for(int i=0;i<30;i++){

        MeleeEnemy mel(textury_mele2[i]);

        if (!textury_mele2[i].loadFromFile("tekstury/mele.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
        mel.setTexture(textury_mele2[i]);

        mel.setPosition(mele_rozm2[2*i],mele_rozm2[2*i+1]);

        mele_wrogowie2.emplace_back(mel);

    }
    for(int i=0;i<10;i++){

        RangeEnemy ran(textury_ran[i]);

        if (!textury_ran[i].loadFromFile("tekstury/range.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
        ran.setTexture(textury_ran[i]);

        ran.setPosition(ran_rozm[2*i],ran_rozm[2*i+1]);

        ran_wrogowie.emplace_back(ran);

    }
    for(int i=0;i<30;i++){

        RangeEnemy ran(textury_ran2[i]);

        if (!textury_ran2[i].loadFromFile("tekstury/range.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
        ran.setTexture(textury_ran2[i]);

        ran.setPosition(ran_rozm2[2*i],ran_rozm2[2*i+1]);

        ran_wrogowie2.emplace_back(ran);

    }
    for(int i=0;i<7;i++){
        sf::RectangleShape wall;
        wall.setPosition(walls_rozm[2*i],walls_rozm[2*i+1]);
        wall.setSize(sf::Vector2f(200,200));
        wall.setFillColor(sf::Color::Red);
        walls.emplace_back(wall);
    }
    for(int i=0;i<4;i++){
        sf::RectangleShape wall;
        wall.setPosition(walls_rozm2[2*i],walls_rozm2[2*i+1]);
        wall.setSize(sf::Vector2f(100,400));
        wall.setFillColor(sf::Color::Red);
        walls2.emplace_back(wall);
    }
    sf::Texture g;
    Terminator term(g);
    sf::Texture texture_term;
    if (!texture_term.loadFromFile("tekstury/term.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    term.setTexture(texture_term);
    term.setPosition(1500, 700);
    sf::Texture b;
    Background bck(b);
    //sf::Texture b;
    if (!b.loadFromFile("tekstury/tlo2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    bck.setTexture(b);
    bck.setPosition(0, 0);
    sf::Texture bc;
    Background bck1(bc);
    //sf::Texture b;
    if (!bc.loadFromFile("tekstury/tlo3.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    bck1.setTexture(bc);
    bck1.setPosition(0, 0);

    sf::Texture bt;
    Button but(bt);
    //sf::Texture b;
    if (!bt.loadFromFile("tekstury/term.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    but.setTexture(bt);
    but.setPosition(0, 0);
    but.scale(2,2);
    sf::Clock clock;
    sf::Clock clc;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type==sf::Event::MouseButtonPressed){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if(level==0){
                        bullet bl(1,term,1);

                        strzaly_gracza.emplace_back(bl);
                    }
                    if(level==1){
                        bullet bl(1,term,1);
                        strzaly_gracza2.emplace_back(bl);
                    }
                }
            }
        }

        if(level==0){
            window.clear(sf::Color::Black);
            sf::Time stoper =clc.getElapsedTime();
            //std::cout<<stoper.asSeconds()<<std::endl;
            if(stoper.asSeconds()>1){
                for(auto&el:ran_wrogowie){
                    sf::Vector2f range_position=el.getPosition();
                    bullet bl(range_position.x,term,range_position.y);
                    bl.setPosition(range_position.x,range_position.y);
                    obiekty.emplace_back(bl);
                }
                clc.restart();
            }

            sf::Time elapsed = clock.restart();

            if(mele_wrogowie.empty()&&ran_wrogowie.empty()&&level==0){
                level=1;
            }
            //--------------------------------------------if()

            int j=0;
            for(auto&element:mele_wrogowie){
                for(auto&el:strzaly_gracza){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        mele_wrogowie.erase(mele_wrogowie.begin()+j);
                    }
                }
                j++;
            }
            int g=0;
            for(auto&element:ran_wrogowie){
                for(auto&el:strzaly_gracza){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        ran_wrogowie.erase(ran_wrogowie.begin()+g);
                    }
                }
                g++;
            }
            int delta=0;
            for(auto&element:walls){
                for(auto&el:strzaly_gracza){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        strzaly_gracza.erase(strzaly_gracza.begin()+delta);
                    }
                }
                delta++;
            }
            for(auto&element:walls){
                for(auto&el:mele_wrogowie){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                      el.sciana(el,element);
                    }
                }

            }
            int gamma=0;
            for(auto&element:walls){
                for(auto&el:obiekty){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        obiekty.erase(obiekty.begin()+gamma);
                    }
                }
                gamma++;
            }
            for(auto&el:obiekty){
                el.strzal(el,elapsed,50,0,0);
            }
            for(auto&el:strzaly_gracza){
                sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                el.strzal(el,elapsed,term,mouse_position.x,mouse_position.y);
            }
            for(auto&el:mele_wrogowie){
                el.auto_pilot(el,term,elapsed);
                term.get_hit_mele(term,el);
            }
            sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            term.ruch(term,elapsed,mouse_position.x,mouse_position.y);
            int k=0;
            window.draw(bck);
            for(auto&el:obiekty){
                sf::FloatRect ob=el.getGlobalBounds();
                if(ob.intersects(term.getGlobalBounds())){
                    obiekty.erase(obiekty.begin()+k);

                }
                k++;
                term.get_hit(term,el);
                window.draw(el);
            }
            for(auto&el:mele_wrogowie){
                window.draw(el);
            }
            for(auto&el:ran_wrogowie){

                window.draw(el);
            }
            for(auto&el:strzaly_gracza){
                window.draw(el);
            }
            for(auto&el:walls){
             window.draw(el);
            }
                window.draw(term);

        }
        //-----------------------------------------------------------------------
        if(level==1){


            window.clear(sf::Color::Black);
            if(pomocniczy==0){
                term.setPosition(1500,700);
                pomocniczy =1;
            }
            sf::Time stoper =clc.getElapsedTime();
            //std::cout<<stoper.asSeconds()<<std::endl;
            if(stoper.asSeconds()>1){
                for(auto&el:ran_wrogowie2){
                    sf::Vector2f range_position=el.getPosition();
                    bullet bl(range_position.x,term,range_position.y);
                    bl.setPosition(range_position.x,range_position.y);
                    obiekty2.emplace_back(bl);
                }
                clc.restart();
            }

            sf::Time elapsed = clock.restart();
            int j=0;
            for(auto&element:mele_wrogowie2){
                for(auto&el:strzaly_gracza2){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        mele_wrogowie2.erase(mele_wrogowie2.begin()+j);
                    }
                }
                j++;
            }
            int g=0;
            for(auto&element:ran_wrogowie2){
                for(auto&el:strzaly_gracza2){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        ran_wrogowie2.erase(ran_wrogowie2.begin()+g);
                    }
                }
                g++;
            }
            int delta=0;
            for(auto&element:walls2){
                for(auto&el:strzaly_gracza2){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        strzaly_gracza2.erase(strzaly_gracza2.begin()+delta);
                    }
                }
                delta++;
            }
            int gamma=0;
            for(auto&element:walls2){
                for(auto&el:obiekty2){

                    sf::FloatRect ob=el.getGlobalBounds();
                    if(ob.intersects(element.getGlobalBounds())){
                        obiekty2.erase(obiekty2.begin()+gamma);
                    }
                }
                gamma++;
            }
            for(auto&el:obiekty2){
                el.strzal(el,elapsed,50,0,0);
            }
            for(auto&el:strzaly_gracza2){
                sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                el.strzal(el,elapsed,term,mouse_position.x,mouse_position.y);
            }
            for(auto&el:mele_wrogowie2){
                el.auto_pilot(el,term,elapsed);
                term.get_hit_mele(term,el);
            }
            sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            term.ruch(term,elapsed,mouse_position.x,mouse_position.y);
            int k=0;
            window.draw(bck1);
            for(auto&el:obiekty2){
                sf::FloatRect ob=el.getGlobalBounds();
                if(ob.intersects(term.getGlobalBounds())){
                    obiekty2.erase(obiekty2.begin()+k);

                }
                k++;
                term.get_hit(term,el);
                window.draw(el);
            }
            for(auto&el:mele_wrogowie2){
                window.draw(el);
            }
            for(auto&el:ran_wrogowie2){

                window.draw(el);
            }
            for(auto&el:strzaly_gracza2){
                if(!but.get_hit(but,el)){
                    window.close();
                    std::cout<<"WYGRANA"<<std::endl;
                }
                window.draw(el);
            }
            for(auto&el:walls2){

                window.draw(el);
            }
            window.draw(term);
            window.draw(but);

        }

        window.display();
    }
    return 0;
}
