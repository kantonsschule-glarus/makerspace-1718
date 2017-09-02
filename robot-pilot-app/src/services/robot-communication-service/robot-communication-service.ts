import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
import 'rxjs/add/operator/map';

/*
  Generated class for the RobotCommunicationServiceProvider provider.

  See https://angular.io/docs/ts/latest/guide/dependency-injection.html
  for more info on services and Angular DI.
*/
@Injectable()
export class RobotCommunicationService {

  constructor(public http: Http) {
    console.log('Hello RobotCommunicationService');
  }

  setSpeedLeftWheel(value: number):void{
      console.log("speed value for left wheel:",value);
  }

    setSpeedRightWheel(value: number):void{
        console.log("speed value for right wheel:",value);
    }
}
