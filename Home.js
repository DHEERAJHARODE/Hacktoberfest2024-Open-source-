import React from 'react'

import { Link } from 'react-router-dom'
function Home() {
  return (<>
   

<div className='home'  >
    <h1 className='head'> TIC-TAC-TOE </h1>
      <div className='bo'> 
           <div className=' e comp'><Link to='/comp' style={{color: 'white'} } > One Player </Link>
           </div>
           <div className=' e two'> <Link to='/two'  style={{color: 'white'}}>Two Player</Link>
          </div>
      </div>
</div>
</>
  )
}

export default Home