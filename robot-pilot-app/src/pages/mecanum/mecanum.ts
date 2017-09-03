import { Component } from '@angular/core';
import { IonicPage, NavController } from 'ionic-angular';
import {HomePage} from "../home/home";

@IonicPage()
@Component({
  selector: 'page-mecanum',
  templateUrl: 'mecanum.html',
})
export class MecanumPage {

  public directionX: number = 375;
  public directionY: number = 125;
  public roationY: number = 125;
  public alpha: number = 0;
  public rotationSpeed: number = 0;
  public xSpeed: number = 0;
  public ySpeed: number = 0;
  public data: number[] = [0,0,0];

  constructor(public navCtrl: NavController) {
  }

  getDirectionXY(e){
      this.directionX = e.srcEvent.offsetX
      this.directionY = e.srcEvent.offsetY

      if(125 < (Math.sqrt((((this.directionY-125)*(this.directionY-125))+((this.directionX-375)*(this.directionX-375)))))){
        this.alpha = Math.atan((Math.abs((this.directionY-125))/Math.abs((this.directionX-375))))
        this.directionY = Math.round((125+(((this.directionY-125) / Math.abs((this.directionY-125))) * (125 * Math.sin(this.alpha)))))
        this.directionX = Math.round((375+(((this.directionX-375) / Math.abs((this.directionX-375))) * (125 * Math.cos(this.alpha)))))
      }

      if(e.isFinal){
          this.directionX = 375
          this.directionY = 125
      }
  }

  getRoationY(e){
    this.roationY = e.srcEvent.offsetY

    if(this.roationY > 250){
      this.roationY = 250
    }
    else if(this.roationY < 0){
      this.roationY = 0
    }

    if(e.isFinal){
      this.roationY = 125
    }
  }

  /*returns speed value in array from -1,1
    method is not finished, since it can only return 0.704 as a max value when trigger is at 45 degree
    which means robot can't drive with full speed diagonal but method works with this exception
   */
  getData(){
    this.rotationSpeed = (((250 - this.roationY)/125) - 1)
    this.xSpeed = ((((250 - (this.directionX-250))/125) - 1)* -1)
    this.ySpeed = (((250 - this.directionY)/125) - 1)
    this.data = [this.xSpeed,this.ySpeed,this.rotationSpeed]
    return this.data
  }

  goToHome(){
    this.navCtrl.push(HomePage)
  }
}
