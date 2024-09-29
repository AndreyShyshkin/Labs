export default function Footer() {
	const footerNavs = [
		{
			href: 'https://github.com/AndreyShyshkin',
			name: 'GitHub',
			img: 'https://cdn-icons-png.flaticon.com/512/25/25231.png',
		},
		{
			href: 'https://linkedin.com/in/shyshkin-andrey',
			name: 'LinkedIn',
			img: 'https://cdn-icons-png.flaticon.com/512/174/174857.png',
		},
	]
	return (
		<footer className='pt-10 relative'>
			<div className='max-w-screen-xl mx-auto px-6 lg:px-8 text-gray-600'>
				<div className='mt-10 py-10 border-t items-center justify-between sm:flex'>
					<p>Design by SHYSHKIN</p>
					<ul className='flex flex-wrap items-center gap-4 mt-6 sm:text-sm sm:mt-0'>
						{footerNavs.map((item, idx) => (
							<li
								key={idx}
								className='text-gray-800 hover:text-gray-500 duration-150'
							>
								<a key={idx} href={item.href}>
									<img className='w-6 h-6' src={item.img} alt={item.name} />
								</a>
							</li>
						))}
					</ul>
				</div>
			</div>
		</footer>
	)
}
