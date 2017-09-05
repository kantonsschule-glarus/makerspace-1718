import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import {MecanumPage} from "../mecanum/mecanum";
import {HomePage} from "../home/home";

@IonicPage()
@Component({
  selector: 'page-button',
  templateUrl: 'button.html',
})
export class ButtonPage {

  public speed: number = 50;
  public leftSpeed: number = 0;
  public rightSpeed: number = 0;
  public data: number[] = [0,0];

  constructor(public navCtrl: NavController, public navParams: NavParams) {
  }

  forward(){
    this.rightSpeed = (this.speed/255)
    this.leftSpeed = (this.speed/255)
  }

  backward(){
    this.rightSpeed = -(this.speed/255)
    this.leftSpeed = -(this.speed/255)
  }

  turnRight(){
    this.rightSpeed = -(this.speed/255)
    this.leftSpeed = (this.speed/255)
  }

  turnLeft(){
    this.rightSpeed = (this.speed/255)
    this.leftSpeed = -(this.speed/255)
  }

  stop(){
    this.rightSpeed = 0
    this.leftSpeed = 0
  }

  getData(){
    this.data = [this.leftSpeed,this.rightSpeed]
    return this.data
  }

  goToHome(){
    this.navCtrl.push(HomePage)
  }

  goToMecanum(){
    this.navCtrl.push(MecanumPage)
  }
}
