import { Component, OnInit } from '@angular/core';
import { UserIn } from '../inputData'
@Component({
  selector: 'ns-input-page',
  templateUrl: './input-page.component.html',
  styleUrls: ['./input-page.component.css']
})

export class InputPageComponent implements OnInit {
  _bottIn = 0;
  _widthIn=0.00;

  constructor() { }

  ngOnInit(): void {
  }

  saveBottles(){
    UserIn.bottleCount = this._bottIn;
    this._bottIn = 0;
  }

  saveWidth(){
    UserIn.width = this._widthIn;
    this._widthIn = 0;
  }
}
