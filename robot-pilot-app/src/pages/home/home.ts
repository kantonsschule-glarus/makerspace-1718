import {Component, OnInit} from '@angular/core';
import { NavController } from 'ionic-angular';
import {RobotCommunicationService} from "../../services/robot-communication-service/robot-communication-service";

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage implements OnInit {

  public startDirectionX: number = 375;
  public startDirectionY: number = 200;
  public startRotationY: number = 200;
  public directionX: number = 375;
  public directionY: number = 125;
  public roationY: number = 125;

  constructor(public robotCommunicationService: RobotCommunicationService, public navCtrl: NavController) {;}

  ngOnInit(){
//    this.robotCommunicationService.setLeftWheelVelocity(0.2);
//    this.robotCommunicationService.setRightWheelVelocity(-0.2);
  }

  getDirectionXY(e){
    this.directionX = e.srcEvent.offsetX
    this.directionY = e.srcEvent.offsetY
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
}
