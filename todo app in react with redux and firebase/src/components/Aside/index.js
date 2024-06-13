
import Anchor from '../Anchor';
import './style.css';

export default function Sidebar({title, text, button}) {
    return (
        <div className='py-3 d-flex flex-column justify-content-center align-items-center bg-sidebar text-light'>
            <h1>{title}</h1>
            <p className='text-center mx-5'>{text}</p>
            <Anchor style='btn anchor-outline' text={button.title} link={button.url}/>
        </div>
    )
}