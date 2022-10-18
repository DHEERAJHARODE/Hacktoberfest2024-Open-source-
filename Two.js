import React from 'react'
import Square from './Square'
import { useEffect } from 'react'
const initial = ["", "", "", "", "", "", "", "", ""]
function Two() {
  const [game, setgame] = React.useState(initial);
  const [step, setstep] = React.useState(0);
  const [win, setwin] = React.useState(null)
  const [scx, setscx] = React.useState(0);
  const [scy, setscy] = React.useState(0);
 
  const clickhandle = (event) => {
    const copy = [...game]
    if (!event.target.innerText) {
      copy[event.target.id] = step%2===0 ? 'X' : 'O'
      setstep(step + 1)
      setgame(copy)
    }
  }
 
  const start = () => {
    setstep(0)
    setgame(initial)
    setwin(null)
  }
useEffect(() => { 
    checkWinner()
  
}, [game])

  function checkWinner() {
    const lines = [
      [0, 1, 2],
      [3, 4, 5],
      [6, 7, 8],
      [0, 3, 6],
      [1, 4, 7],
      [2, 5, 8],
      [0, 4, 8],
      [2, 4, 6],
    ];

    for (let i = 0; i < lines.length; i++) {
      const [a, b, c] = lines[i];
      if (game[a] && game[a] === game[b] && game[a] === game[c]) {
        setwin(game[a]);

        console.log("winner");
        if (game[a] === 'X') { setscx(scx + 1); }
        else { setscy(scy + 1); }
      }
    }

  }
  return (
    <div className='container'>
      <div className='leftwrap'>
        <div className='lefttext'>Let's Play the Tic-tac-toe Game!</div>
        <div className='button' onClick={start}> Start a New Game</div>
      </div>
      {!win && step < 9 && <div className='right'>
        <div className='ps'>
          <div className={`p ${step % 2 === 0 && "px"}`}>Player X : {scx}
          </div>
          <div className={`p ${step % 2 === 1 && "po"}`}> Player Y : {scy}
          </div>
        </div>
        <div className='game' onClick={clickhandle} >
          <Square id={0} state={game[0]} className='border-right-bottom' />
          <Square id={1} state={game[1]} className='border-right-bottom' />
          <Square id={2} state={game[2]} className='border-bottom' />
          <Square id={3} state={game[3]} className='border-right-bottom' />
          <Square id={4} state={game[4]} className='border-right-bottom' />
          <Square id={5} state={game[5]} className='border-bottom' />
          <Square id={6} state={game[6]} className='border-right' />
          <Square id={7} state={game[7]} className='border-right' />
          <Square id={8} state={game[8]} />
       
        </div>

      </div>}
      {(win || step === 9) && <div className='winner'>
        <img src='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQecoJbYaU6q5_jdM4Bi9uUcjQGvhoxbM29kw&usqp=CAU' />
        <div className='wintext'> {!win && step === 9 ? "Its a Draw" : `${win} Win !`}</div>
        <div className='score'>
          <div className='p1'>Player 1 : {scx}</div>

          <div className='p2'>Player 2 : {scy}</div>
        </div>
      </div>}

    </div>
  )
}

export default Two;